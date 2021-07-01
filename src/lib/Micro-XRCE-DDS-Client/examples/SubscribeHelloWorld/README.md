# SubscribeHelloWorld example

This example will show how to receive data from the DDS World creating a client subscriber.
In order to compile this example, it is necessary to have the following profiles enabled in `client.config` file:

- `UCLIENT_PROFILE_UDP`

## Usage
1. Run an agent in port *2018*.
2. Run the *PublisherHelloWorld* example or some publisher that can send the *HelloWorld* topic.
3. Run the *SubscriberHelloWorld* example.
   The example can be parameterized with the number of topics that will be listened.
   If no number is given, the publisher will publish indefinitely.

## Topic

The *HelloWorld* topic has the following *IDL* representation:

```
struct HelloWorld
{
	unsigned long index;
	string message;
};
```

