#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    virtual void showCharacteristics() const = 0;
    virtual ~Device() {}
};

class GPU : public Device {
public:
    void showCharacteristics() const override {
        cout << "Видеокарта: NVIDIA GeForce RTX 3060, 12GB, 192-bit" << endl;
    }
};

class CPU : public Device {
public:
    void showCharacteristics() const override {
        cout << "Процессор: Intel Core i7-12700K, 12 ядер, 3.6GHz" << endl;
    }
};

class HDD : public Device {
public:
    void showCharacteristics() const override {
        cout << "Жесткий диск: Seagate 2TB, 7200 RPM, SATA III" << endl;
    }
};

class RAM : public Device {
public:
    void showCharacteristics() const override {
        cout << "Оперативная память: 16GB DDR4, 3200MHz" << endl;
    }
};

class DeviceReporter {
protected:
    Device* device;
public:
    DeviceReporter(Device* d) : device(d) {}
    virtual void printReport() const {
        device->showCharacteristics();
    }
    virtual ~DeviceReporter() {}
};

class DetailedDeviceReporter : public DeviceReporter {
public:
    DetailedDeviceReporter(Device* d) : DeviceReporter(d) {}

    void printReport() const override {
        cout << "--- Отчет о характеристиках устройства ---" << endl;
        device->showCharacteristics();
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    Device* gpu = new GPU();
    Device* cpu = new CPU();
    Device* hdd = new HDD();
    Device* ram = new RAM();

    DetailedDeviceReporter reporter1(gpu);
    DetailedDeviceReporter reporter2(cpu);
    DetailedDeviceReporter reporter3(hdd);
    DetailedDeviceReporter reporter4(ram);

    reporter1.printReport();
    reporter2.printReport();
    reporter3.printReport();
    reporter4.printReport();

    delete gpu;
    delete cpu;
    delete hdd;
    delete ram;

    return 0;
}
