#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QSerialPort>
#include <QPrinter>

class BarCode;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    BarCode *barcode;
private slots:
    void check_serial_port();
    void serialport_recv();

    void on_open_port_Button_clicked();

    void on_print_button_clicked();
    void plotPic(QPrinter *printer);

    void on_rencode_lineEdit_2_textChanged(const QString &arg1);

    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    void InitStyle();   //初始化无边框窗体
    void InitForm();    //初始化窗体数据
    void port_param_init();
    void open_serialport();
    void close_serialport();
    void QRcode_Encode(QByteArray &text);
    void QRcode_Encode_2(QByteArray &text);
    void QBarcode_ts102(QByteArray &text);//条形码显示
    void QPcode(QPrinter *printer,QPainter *painter,QByteArray &text);//单张二维码打印
    void QPcode_2(QPrinter *printer,QPainter *painter,QByteArray &text,QByteArray &text_2);//两张二维码打印

    QRect location;     //鼠标移动窗体后的坐标位置
    QColor foreground;
    QColor background;
    QByteArray rencode_text;//记录MAC地址
    QByteArray rencode_text_2;//记录第一个MAC地址
    quint8 state=0;
    QByteArray recv_arr;
    void log_output(QString info);
    void FrameParse(char c);
    QSerialPort *serialport;
    #define IMAGE_SIZE 200 //定义在上位机显示二维码大小
    /***************************************
     * 设置viewsize windonwsize
     * ************************************/
    #define VIEWSIZE_WITH 40
    #define VIEWWIZE_HIGHT 30
    #define WINDONWSIZE_WITH 40
    #define WINDONWSIZE_HIGHT 30

    /***************************************
     * 两张规格
     * 上边距：1.89mm   左边距：2.29mm  二维码大小13mmx13mm
     * *************************************/
    #define D_MARGIN_VALUE 0
    #define D_DPI 25.5 //毫米和像素的转换
    #define D_PARAMETER 3.775
    #define D_TWODIMENSION_SIZE 13*D_PARAMETER //定义打印二维码图像大小
    #define D_LEFT_MARGIN 2.29*D_PARAMETER  //左边距2.29mm
    #define D_UP_MARGIN 1.89*D_PARAMETER
    #define D_TWODIMENSION_INTERVAL 3.58*D_PARAMETER
    /***************************************
     * 单张规格：
     * 上边距：1.86mm   左边距：1.67mm  二维码到文字的距离：1.7mm 二维码大小：12mmx12mm
     * *************************************/
    #define S_MARGIN_VALUE 0
    #define S_DPI 25.4
    #define S_PARAMETER 3.775
    #define S_UP_MARGIN 1.86*S_PARAMETER
    #define S_LEFT_MARGIN 1.67*S_PARAMETER
    #define S_TEXT_TWODIMENSION 1.7*S_PARAMETER
    #define S_TWODIMENSION_SIZE 12*S_PARAMETER
};

#endif // MAINWINDOW_H