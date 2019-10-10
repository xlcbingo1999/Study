<!--关于链接邮件发送的相关问题-->

在进行邮件内容发送时，需要使用关键字：mailto

示例如下：

<a href="mailto:zhangrr601@163.com?subject=这是邮件的主题&body=这是邮件的内容" rel="nofollow">发送邮件</a>

这样会调启系统默认的邮件程序发送给 zhangrr601@163.com，并且收件人那里已经填上了我邮箱的地址。
关于创建电子邮件链接时如何进行抄送，密送.
在进行抄送时，需要使用关键字：cc
在进行密送时，需要使用关键字：bcc

示例如下：

<a href="mailto:zhangrr601@163.com?cc=someone@163.com&bcc=somebody@163.com" rel="nofollow">发送邮件</a>

参数说明:

mailto:name@email.com 邮件接收地址

cc=name@email.com  抄送地址

bcc=name@email.com 密件抄送地址

subject=subject text  邮件主题

body=body text 邮件内容 

? 第一个参数分隔符

&  其他参数分隔符

注：多个邮件地址用 ; 隔开，空格用 %20 代替。