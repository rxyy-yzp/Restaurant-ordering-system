# Restaurant-ordering-system
餐馆点餐系统  
程序功能：  
编写一个程序，该程序可以辅助当地餐馆自动管理早餐付账系统，程序功能如下：  
a.	向顾客显示餐馆提供的早餐品种；  
b.	允许顾客在菜单中选择多种早餐；  
c.	计算和打印账单，保留两位小数。  
假设餐馆提供以下的早餐品种（每种早餐的价格列在早餐种类的右边）。  
Plain Egg										$1.45  
Bacon        									$2.45  
Muffin											$0.99  
French Toast									$1.99  
Fruit Basket									$2.49  
Cereal											$0.69  
Coffee											$0.50  
Tea												$0.75  
设计要求：  
⑴ 试定义menuItemType结构体类型，其中有早晨菜单menuItem和相应的菜单价格menuPrice两个成员。  
⑵ 编写函数。  
程序使用menuItemType类型的结构数组menuList。menuItemType的定义在⑴中，该程序必须包含以下的函数：  
①	getData()：把输入的数据存储到数组menuList中。           
②	showMenu()：显示餐馆提供的早餐品种，并提示顾客怎样选择早餐。  
③	printCheck()：计算和打印账单（注意账单应该包含5%的税）。  
④	printCheck()： 将账单收入记录到文件中。  
⑤	编写主函数，对上述编写的各函数的功能进行调用。 
       输出格式要求：一个范例输出格式如下所示：  
Welcome to Johnny’s Restaurant  
1    Bacon        									$2.45  
2    Muffin										$1.98  
3    Coffee										$0.50  
Tax											$0.25  
Amount Due									$5.18  
显示屏上的输出格式要求如下：小数要有两位有效数字，早餐名称应该是左对齐的。  
