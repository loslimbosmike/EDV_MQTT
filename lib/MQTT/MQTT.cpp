#include <MQTT.h>

WiFiClient espClient;
PubSubClient client(espClient);

const char *ssid = "Hotwheels_phone";
const char *pwd = "NaomiLove2011";
const char *broker = "81.207.241.121";
const char *inTopic = "/epilepsie/alert";

char _msg;

void setupWifi()
{
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Create a random client ID
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);
        // Attempt to connect
        if (client.connect(clientId.c_str()))
        {
            Serial.println("connected");
            client.subscribe(inTopic);
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" trying again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}
void callBack(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();

    _msg = (char)payload[0];
}
void MQTT::start()
{
    Serial.begin(115200);
    setupWifi();
    client.setServer(broker, 1883);
    client.setCallback(callBack);
}
void MQTT::readMSG(char *msg)
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();

    *msg = _msg;
}