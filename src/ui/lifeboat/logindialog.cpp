#include "logindialog.h"
#include "lifeboat_autogen/include/ui_logindialog.h"
#include "../../multiplayer/lifeboat/player.h"

LoginDialog::LoginDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::LoginDialog) {
    ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
    delete ui;
}

std::string LoginDialog::on_pushButton_clicked() {
    Player client(CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.run_client(ui->lineEdit->text().toStdString());
    return ui->lineEdit->text().toStdString();
}
