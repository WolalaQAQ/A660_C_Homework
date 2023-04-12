#include "GAppMain.h"

void GApp(int argc, char *argv[]) {
  gtk_init(&argc, &argv);
  MainWindow(NULL, NULL);
  gtk_main();
}
