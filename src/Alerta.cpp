#include "include/Alerta.h"

void alertMensagem(std::string frase)
{
    QMessageBox msg;
    msg.setWindowTitle("Alerta");
    msg.setText(QString::fromStdString(frase));
    msg.exec();
}
