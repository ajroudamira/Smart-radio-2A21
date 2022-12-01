#include "scenario1arduino.h"

scenario1arduino::scenario1arduino()
    {
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

    int scenario1arduino:: connect_arduino ()
    {
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if (serial_port_info.hasVendorIdentifier () && serial_port_info.hasProductIdentifier ()){
    if(serial_port_info.vendorIdentifier () == arduino_uno_vendor_id && serial_port_info.productIdentifier ()== arduino_uno_producy_id) {
    arduino_is_available = true;
    arduino_port_name=serial_port_info.portName () ;
    } }}
    if(arduino_is_available){
    serial->setPortName(arduino_port_name);
    if(serial->open(QSerialPort::ReadWrite)){
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits (QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits (QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    return 0;}
    return 1;}
    return -1;
    }
    int scenario1arduino::close_arduino()
    {
    if(serial->isOpen()){
    serial->close();
    return 0;
    }
    return 1;
    }
    QByteArray scenario1arduino::read_from_arduino()
    {
    if(serial->isReadable())
    {
    data=serial->readAll(); //récupérer les données reçues
    return data;
    }
    }
    int scenario1arduino::write_to_arduino( QByteArray d)
    {
    if (serial->isWritable()){
    serial->write(d); // envoyer des données vers Arduino
    }
    }
    QString scenario1arduino::getarduino_port_name(){
        return arduino_port_name;
    }
    QSerialPort* scenario1arduino::getserial(){return serial;}

