#ifndef Network_H
#define Network_H

void connectToWifi(const char *ssid,const char *password);
bool scanSSID(const char *ssid);
void connectSSID(const char *ssid,const char *password);

#endif // Network_H
