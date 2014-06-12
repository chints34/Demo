//#include <gtk/gtk.h>
//#include </home/likewise-open/RADIXLOCAL/chintan.patel/gtk+-3.2.0/gtk>

// gcc base.c -o base `pkg-config --cflags --libs gtk+-3.0`

#include "/usr/include/gtk-3.0/gtk/gtk.h"
#define GTK_ENABLE_BROKEN

void static call(GtkWidget *widget,gpointer data)
{
    g_print("%s \n",(gchar*) data);
}






int main(int argc,char **argv)
{
GtkWidget *window,*button,*box,*entry;

gtk_init(&argc,&argv);
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
 gtk_window_set_title(GTK_WINDOW(window),"My gui");
box=gtk_box_new(0,0);
button=gtk_button_new_with_label("button 1");
g_signal_connect(button,"clicked",G_CALLBACK(call),(gpointer) "BUTTON 1");
gtk_box_pack_start(GTK_BOX(box),button,0,0,0);

//button=gtk_button_new_with_label("button 2");
//box=gtk_box_new(0,0);
button=gtk_button_new_with_label("button 2");
gtk_box_pack_start(GTK_BOX(box),button,1,0,1);
g_signal_connect(button,"clicked",G_CALLBACK(call),(gpointer) "BUTTON 2");
/////////////////////////////////
button=gtk_button_new_with_label("quit");
g_signal_connect(button,"clicked",G_CALLBACK(gtk_main_quit),(gpointer) "quit");
gtk_box_pack_start(GTK_BOX(box),button,0,0,0);


  entry = gtk_entry_new ();
  gtk_entry_set_max_length (GTK_ENTRY (entry),0); 
  gtk_box_pack_start(GTK_BOX(box),entry,0,0,5);



//gtk_container_set_border_width(GTK_CONTAINER(window),20);
gtk_container_add(GTK_CONTAINER(window),box); 
//gtk_container_add(GTK_CONTAINER(window),entry);
gtk_widget_show_all(window);
gtk_main();
return 0;
}
