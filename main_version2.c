#include <gtk/gtk.h>
#include <string.h>


static gchar *titles[5] = {"编号", "姓名", "出生年月", "电子邮件"};
void destroy( GtkWidget *widget,gpointer   data );
void hello( GtkWidget *widget,gpointer   data );

static void signin (){   //创造登陆界面                                                                                 //申明一个窗口
    //布局
    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);                                      //为app创建一个窗口
 
    gtk_window_set_title(GTK_WINDOW(window) , "登录-lujiapin");              //设置窗口的标题
    gtk_window_set_default_size(GTK_WINDOW(window) , 300 , 240);    //设置窗口默认大小为长宽各200像素
    GtkWidget *sbutton_signin = gtk_button_new_with_label ("登录");
    GtkWidget *align = gtk_alignment_new(0.7,0.5,0.5,0.5);

    /*创建一组组装盒子*/
    GtkWidget *mainbox = gtk_vbox_new(FALSE,0);
    GtkWidget *table = gtk_table_new(2,2,TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(mainbox),40);
    gtk_container_set_border_width(GTK_CONTAINER(table),20);
    	
    /*创建一个文本框，输入框*/
    GtkWidget *label1 = gtk_label_new("用户名：");
    GtkWidget *entry1 = gtk_entry_new();	
    GtkWidget *label2 = gtk_label_new("密  码：");
    GtkWidget *entry2 = gtk_entry_new();	
    gtk_entry_set_visibility(GTK_ENTRY(entry2),FALSE);//密文不可见

    //文本框放入表,把表放入盒
    gtk_box_pack_start(GTK_BOX(mainbox),GTK_WIDGET(table),FALSE,FALSE,0); //组装盒、按钮之间的嵌套
    gtk_container_add(GTK_CONTAINER(align),sbutton_signin); //
    gtk_box_pack_start(GTK_BOX(mainbox),GTK_WIDGET(align),FALSE,FALSE,0);//组装盒、按钮之间的嵌套
    gtk_table_attach(GTK_TABLE(table),label1,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
    gtk_table_attach(GTK_TABLE(table),entry1,1,2,0,1,GTK_FILL,GTK_FILL,0,0);
    gtk_table_attach(GTK_TABLE(table),label2,0,1,1,2,GTK_FILL,GTK_FILL,0,0);
    gtk_table_attach(GTK_TABLE(table),entry2,1,2,1,2,GTK_FILL,GTK_FILL,0,0);
   


    gtk_container_add (GTK_CONTAINER (window), mainbox);
    /* 当按钮收到 "clicked" 信号时会调用 hello() 函数，并将NULL传给
     * 它作为参数。hello() 函数在前面定义了。*/
    //功能---------------------------------------------
    g_signal_connect (G_OBJECT (sbutton_signin), "clicked",G_CALLBACK (hello), NULL);
    g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (destroy), NULL);
    /* 当点击按钮时，会通过调用 gtk_widget_destroy(window) 来关闭窗口。
     * "destroy" 信号会从这里或从窗口管理器发出。*/
    g_signal_connect_swapped (G_OBJECT (sbutton_signin), "clicked", G_CALLBACK (gtk_widget_destroy),window);

    gtk_widget_show_all(window);
}

static void main_window (){  //创造函数主界面
    //布局-------------------------------------------------------
    GtkWidget *window;     
    GtkWidget *box1; //水平
    GtkWidget *box2; //垂直   
    GtkWidget *box3; //垂直  
    GtkWidget *box4; //查找盒
    GtkWidget *box5; //文件列表盒
    GtkWidget *box6; //上传进度盒
    GtkWidget *button1;//上传
    GtkWidget *button2;//下载  
    GtkWidget *button3; //查找    
    GtkWidget *label1;//文件名
    GtkWidget *label2;//进度
    GtkWidget *entry1; //查找  
    GtkWidget *table1; //左上表格
    GtkWidget *table2; //左下表哥
    GtkWidget *text1;  //文件列表
    GtkWidget *progress; //传输进度条 
    GtkWidget *scrolled; //滚动窗口条  
 
    //表、盒间关系
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);                                         //为app创建一个窗口
    box1 = gtk_hbox_new(FALSE,0);
    box2 = gtk_vbox_new(FALSE,0);
    box3 = gtk_vbox_new(FALSE,0);
    box4 = gtk_hbox_new(FALSE,0);
    box5 = gtk_hbox_new(FALSE,0);
    box6 = gtk_hbox_new(FALSE,0);
    table1 = gtk_table_new(1,5,TRUE);
    table2 = gtk_table_new(1,4,TRUE);
    scrolled=gtk_scrolled_window_new(NULL,NULL); /*创建滚动窗口构件*/
    gtk_box_pack_start(GTK_BOX(box1),GTK_WIDGET(box2),FALSE,FALSE,0); //建立关系--盒盒
    gtk_box_pack_start(GTK_BOX(box1),GTK_WIDGET(box3),FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box2),GTK_WIDGET(box4),FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box2),GTK_WIDGET(box5),FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box2),GTK_WIDGET(box6),FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box4),GTK_WIDGET(table1),FALSE,FALSE,0); //表盒
    gtk_box_pack_start(GTK_BOX(box5),GTK_WIDGET(scrolled),FALSE,FALSE,0); //滚动窗口条放入盒5
    gtk_box_pack_start(GTK_BOX(box6),GTK_WIDGET(table2),FALSE,FALSE,0);
       

    //按钮、标签、输入框与表、盒子的关系
    button1 = gtk_button_new_with_label ("上传"); 
    button2 = gtk_button_new_with_label ("下载");
    button3 = gtk_button_new_with_label ("查找");
    label1 = gtk_label_new("文件名：");
    label2 = gtk_label_new("传输进度：");
    entry1 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box3),GTK_WIDGET(button1),FALSE,FALSE,80); //右盒
    gtk_box_pack_start(GTK_BOX(box3),GTK_WIDGET(button2),FALSE,FALSE,0); 
    gtk_table_attach(GTK_TABLE(table1),label1,0,1,0,1,GTK_FILL,GTK_FILL,0,0); //左上
    gtk_table_attach(GTK_TABLE(table1),entry1,1,4,0,1,GTK_FILL,GTK_FILL,0,0);
    gtk_table_attach(GTK_TABLE(table1),button3,4,5,0,1,GTK_FILL,GTK_FILL,0,0);
    gtk_table_attach(GTK_TABLE(table2),label2,0,1,0,1,GTK_FILL,GTK_FILL,0,0); //左下
    

    //进度条、文件列表与盒子关系
    text1 = gtk_clist_new_with_titles(5, titles);
    progress = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress), 0.6); //设置进度条的比例
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress), "60%"); //设置滑槽上的文本显示 
    gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress), GTK_PROGRESS_LEFT_TO_RIGHT);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled),text1);
    gtk_table_attach(GTK_TABLE(table2),progress,1,4,0,1,GTK_FILL,GTK_FILL,0,0);
    //样式微调
    gtk_widget_set_size_request(box3,100,50);
    gtk_widget_set_size_request(button1,50,50);
    gtk_widget_set_size_request(button2,50,50);
    gtk_widget_set_size_request(scrolled,300,300);
    gtk_container_set_border_width(GTK_CONTAINER(box1),20);
    gtk_container_set_border_width(GTK_CONTAINER(box3),20);
    gtk_container_set_border_width(GTK_CONTAINER(box4),10);
    gtk_container_set_border_width(GTK_CONTAINER(box5),10);
    gtk_container_set_border_width(GTK_CONTAINER(box6),10);
    
    //盒与window关系
    gtk_window_set_title(GTK_WINDOW(window) , "文件传输软件-lujiapin");              //设置窗口的标题
    gtk_window_set_default_size(GTK_WINDOW(window) , 440 , 450);    //设置窗口默认大小为长宽各200像素
    gtk_container_add (GTK_CONTAINER (window), box1);

    //功能----------------------------------------------------------
    g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (destroy), NULL);


    gtk_widget_show_all(window);

}


/* 这是一个回调函数。data 参数在本示例中被忽略。
 * 后面有更多的回调函数示例。*/
void hello( GtkWidget *widget,gpointer   data )
{
    g_print ("Hello World\n");
}

gint delete_event( GtkWidget *widget,GdkEvent  *event,gpointer   data )
{
    /* 如果你的 "delete_event" 信号处理函数返回 FALSE，GTK 会发出 "destroy" 信号。
     * 返回 TRUE，你不希望关闭窗口。
     * 当你想弹出“你确定要退出吗?”对话框时它很有用。*/
    g_print ("delete event occurred\n");
    /* 改 TRUE 为 FALSE 程序会关闭，关闭时调用destroy()。*/
    return FALSE;
}
/* 另一个回调函数 */
void destroy( GtkWidget *widget,gpointer   data )
{
    gtk_main_quit ();
}
int main( int   argc, char *argv[] )
{   
    /* 这个函数在所有的 GTK 程序都要调用。参数由命令行中解析出来并且送到该程序中*/
    gtk_init (&argc, &argv);
    signin();
    gtk_main (); /* 这个函数在所有的 GTK 程序都要调用。参数由命令行中解析出来并且送到该程序中*/
    main_window();
    gtk_main ();
   
    return 0;
}
