# PublishHelloWorldP2P example

This example will show how to publish data creating a client publisher.
It is necessary to have the following profiles enabled in `client.config` file to compile this example:

- `UCLIENT_PROFILE_UDP`

## Usage
1. Run an agent in port *2018*.
2. Run the *SubscriberHelloWorldP2P* example or some subscriber that can read the *HelloWorld* topic.
3. Run the *PublisherHelloWorldP2P* example.
   The example can be parameterized with the number of topics that will be sent.
   If no number is given, the subscriber will listen indefinitely.

## Topic

The *HelloWorld* topic has the following *IDL* representation:

```
struct HelloWorld
{
	unsigned long index;
	string message;
};
```

