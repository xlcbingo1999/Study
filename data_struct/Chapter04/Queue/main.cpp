#include "NodeExtendedQueue.h"
#include "define.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char get_command(){
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter> " << endl << "[A][S][R][#][C][P][H][Q]" << endl;
    while(waiting){
        cin >> command;
        command = tolower(command);
        if(command == 'a' || command == 's' || command == 'r' ||
            command == '#' || command == 'c' || command == 'p' ||
            command == 'h' || command == 'q' ){
                waiting = false;
            }
        else
        {
            cout << "Please enter a valid command:" << endl;
            cout << "[A-append][S-serve][R-retrieve][#-GetSize][C-clear][P-print][H-serve and retrieve][Q-quit]" << endl;
        }
    }
    return command;
}

bool do_command(char c , Extended_Queue &test_queue){
   bool continue_input = true;
   Queue_entry x;
   Queue_entry needin;
   switch (c)
   {
   case 'r':
        if(test_queue.empty()){
            cout << "empty" << endl;
        }
        else{
            test_queue.retrieve(x);
            cout << "The first entry is :" << x << endl; 
        }
       break;
    case 'h':
        if(test_queue.empty()){
            cout << "empty" << endl;
        }
        else{
            test_queue.serve_and_retrieve(x);
            cout << "The first entry is :" << x << endl; 
            cout << "You succeed serving." << endl;
        }
        break;
    case 'q':
        cout << "finished" << endl;
        return 0;
    case 'a':
        if(test_queue.full()){
            cout << "full" << endl;
        }
        else{
            cout << "Please enter a number" << endl;
            cin >> needin;
            test_queue.append(needin);
            cout << "You append an entry :" << needin << endl;
        }
        break;
    case 's':
        if(test_queue.empty()){
            cout << "empty" << endl;
        }
        else{
            test_queue.serve();
            cout << "You succeed serving." << endl;
        }
        break;
    case '#':
       if(test_queue.empty()){
            cout << "empty" << endl;
        }
        else{
            cout << test_queue.size() << endl;
        }
        break;
    case 'c':
        test_queue.clear();
        break;
    case 'p':
        if(test_queue.empty()){
            cout << "empty" << endl;
        }
        else{
            test_queue.print();
        }
        break;
   }
   return continue_input;
}


int main(){
    Extended_Queue test_queue;
    while(do_command(get_command(),test_queue));
}
