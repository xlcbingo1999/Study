/*  2019.9.1
泊松分布(Poisson distribution):在较长的子序列上，序列中的整数的平均值接近于v
*/

/*

*/
#include <iostream>
#include <cctype>
#include <system_error>
#include <ctime>
#include <cstdlib>

typedef int Error_code;
const int maxQueue = 10;
#define success 1;
#define overflow 0;
#define underflow -1;

using namespace std;
enum Runway_activity{idle , land, takeoff};
enum Plane_status{null,arriving,departing};

class Plane{
public:
    Plane();
    Plane(int flt,int time,Plane_status status);
    void refuse() const;
    void land(int time) const;
    void fly(int time)const;
    int started()const;
private:
    int flt_num;
    int clock_start;
    Plane_status state;
};

class Runway{
public:
    Runway(int limit);
    Error_code can_land(const Plane &current);
    Error_code can_depart(const Plane &current);
    Runway_activity activity(int time, Plane &moving);
    void shut_down(int time)const;
private:
    Extended_queue landing;
    Extended_queue takeoff;
    int queue_limit;
    int num_land_requests;
    int num_takeoff_requests;
    int num_landings;
    int num_takeoffs;
    int num_land_accepted;
    int num_takeoff_accepted;
    int num_land_refused;
    int num_takeoff_refused;
    int land_wait;
    int takeoff_wait;
    int idle_time;
};

typedef Plane Queue_entry;

class Queue{
public:
    Queue();
    bool empty()const ;
    Error_code serve();
    Error_code retrieve(Queue_entry &x) const;
    Error_code append(const Queue_entry &x); 
    void print()const;
protected:
    int count;
    int front,rear;
    Queue_entry entry[maxQueue];
};


class Extended_queue:public Queue{
public:
    bool full()const;
    int size()const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};
Queue::Queue(){
    count = 0;
    rear = maxQueue - 1;
    front = 0;
}

void Queue::print()const{
    for(int i = front ; i < front + count ; ++ i){  // 打印请从front到front+count
        cout << " " << entry[i] ; 
    }
    cout << endl;
}

Error_code Queue::append(const Queue_entry &item){
    Error_code outcome = success;
    if(count >= maxQueue) {
        outcome = overflow;
    }
    count ++;
    rear = ((rear + 1) == maxQueue) ? 0 : (rear + 1);
    entry[rear] = item;
    return outcome;
}
Error_code Queue::serve(){
    Error_code outcome = success;
    if(count <= 0)  {
        outcome = underflow;
    }
    --count;
    front = ((front + 1) == maxQueue) ? 0 : (front + 1); 
    return outcome;
}
Error_code Queue::retrieve(Queue_entry &item) const{
    Error_code outcome = success;
    if(count <= 0) {
        outcome = underflow;
    }
    else {
        item = entry[front];
    }
    return outcome;
}
bool Queue::empty()const{
    bool outcome = true;
    if(count > 0) {
        outcome = false;
    }
    return outcome;
}
int Extended_queue::size()const{
    return count;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item){
    Error_code outcome = success;
    if(count <= 0)  {
        outcome = underflow;
    }
    item = entry[front];
    --count;
    front = ((front + 1) == maxQueue) ? 0 : (front + 1); 
    return outcome;
}
// 此处应该讨论front的位置
bool Extended_queue::full()const{
    if(count == maxQueue){
        return true;
    }
    return false;
}

void Extended_queue::clear(){
    count = 0;
    front = 0;
    rear = 0;
}


Plane::Plane(){
    flt_num = -1;
    clock_start = -1;
    state = null;
}

Plane::Plane(int flt , int time , Plane_status status){
    flt_num = flt;
    clock_start = time;
    state = status;
    cout << "plane number" << flt << "ready to" ;
    if(status == arriving){
        cout << "land." << endl;
    }
    else{
        cout << "take off." << endl;
    }
}

void Plane::refuse()const{
    cout << "Plane number:" << flt_num;
    if(state == arriving){
        cout << "directed to another airport" << endl;
    }
    else{
        cout << "told to try to takeoff again later." << endl;
    }
}

void Plane::land(int time)const{
    int wait = time - clock_start;
    cout << time << ":Plane number" << flt_num << "landed after"
        << wait << " time unit" << ((wait == 1)? "":"s") 
        << " in the takeoff queue." << endl;
}

void Plane::fly(int time)const{
    int wait = time - clock_start;
    cout << time << ":Plane number" << flt_num << "took off after"
        << wait << " time unit" << ((wait == 1) ? "":"s")
        << " in the takeoff queue." << endl;
}

int Plane::started()const
/* Post: return the time that the plane entered the airport system.*/
{
    return clock_start;
}



Runway::Runway(int limit){
    queue_limit = limit;
    num_land_requests = 0;
    num_takeoff_requests = 0;
    num_landings = 0;
    num_takeoffs = 0;
    num_land_refused = 0;
    num_takeoff_refused = 0;
    num_land_accepted = 0;
    num_takeoff_accepted = 0;
    land_wait = 0;
    takeoff_wait = 0;
    idle_time = 0;
}

Error_code Runway::can_land(const Plane &current){
    Error_code result;
    if(landing.size() < queue_limit){
        result = landing.append(current);
    }
    else{
        result = false; // ????
    }
    num_land_accepted++;
    return result;
}

Error_code Runway::can_depart(const Plane &current){
    Error_code result;
    if(takeoff.size() < queue_limit){
        result = takeoff.append(current);
    }
    else{
        result = false;
    }
    num_takeoff_requests++;
    if((int)result != success){
        num_takeoff_refused++;
    }
    else{
        num_takeoff_accepted++;
    }
    return result;
}
Runway_activity Runway::activity(int time , Plane &moving){
    Runway_activity in_progress;
    if(!landing.empty()){
        landing.retrieve(moving);
        land_wait += time - moving.started();
        num_landings++;
        in_progress = land;
        landing.serve();
    }
    else if(!takeoff.empty()){
        takeoff.retrieve(moving);
        takeoff_wait += time - moving.started();
        num_takeoffs++;
        in_progress = takeoff;
        takeoff.serve();
    }
    else{
        idle_time++;
        in_progress = idle;
    }
    return in_progress;
}

initialize(int &end_time , int &queue_limit , 
            double &arrival_rate ,double &departure_rate){
    cout << "This program simulates an airport with only one runway." << endl 
        << "One plane can land or depart in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land"
        << "or take off at any time?" << endl;

    cin >> queue_limit;
    cout << "How many units of time will the simulation run?" << endl;
    
    cin >> end_time;
    bool acceptable;
    do{
        cout << "Expected number of arrivals per unit time?" << endl;
        cin >> arrival_rate;
        cout << "Expected number of arrivals per unit time?" << endl;
        cin >> departure_rate;
        if(arrival_rate < 0.0 || departure_rate < 0.0){
            cerr << "These rate must be nonnegative" << endl;
        }
        else{
            acceptable = true;
        }
        if(acceptable && arrival_rate + departure_rate > 1.0){
            cerr << "Safety Warning: This airport will become saturated." << endl;
        }
    }while(!acceptable);
}
void run_idle(int time){
    cout << time << " :Runway is idle." << endl;
}

void Runway::shut_down(int time)const{
    cout << "Simulation has conluded after" << time << " time units." << endl
        << "Total number of planes processed"
        << (num_land_requests + num_takeoff_requests) << endl
        << "Total number of planes asking to land"
        << num_takeoff_requests << endl
        << "Total number of planes accepted for landing"
        << num_land_accepted << endl
        << "Total number of planes accepted for takeoff"
        << num_takeoff_accepted << endl
        << "Total number of planes refused for landing"
        << num_land_refused << endl
        << "Total number of planes refused for takeoff"
        << num_takeoff_refused << endl
        << "Total number of planes that landed"
        << num_landings << endl
        << "Total number of planes that took off"
        << num_takeoffs << endl
        << "Total number of planes left in landing queue"
        << landing.size() << endl
        << "Total number of planes left in takeoff queue"
        << takeoff.size() << endl;
}


int main(){
    int end_time;
    int queue_limit;
    int flight_number = 0;
    double arrival_rate,departure_rate;
    initialize(end_time , queue_limit , arrival_rate ,departure_rate);
    int number_arrivals = 7;
    int number_departures = 6;
    Runway small_airport(queue_limit);
    for(int current_time = 0 ; current_time < end_time ; ++current_time){
        //int number_arrivals = variable.poisson(arrival_rate);
        for(int i = 0 ; i < number_arrivals ; ++i){
            Plane current_plane(flight_number++ , current_time , arriving);
            if(small_airport.can_land(current_plane)!=success){
                current_plane.refuse();
            }
        }
        //int number_departures = variable.poisson(departure_rate);
        for(int j = 0 ; j < number_departures ; ++j){
            Plane current_plane(flight_number++ , current_time , departing);
            if(small_airport.can_depart(current_plane)!= success){
                current_plane.refuse();
            }
        }
        Plane moving_plane;
        switch (small_airport.activity(current_time.moving_plane))
        {
            case land:
            moving_plane.land(current_time);
            break;
            case takeoff:
            moving_plane.fly(current_time);
            break;
            case idle:
            run_idle(current_time);
        }
    }
    small_airport.shut_down(end_time);
}