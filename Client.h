#include "Email.h"
#include "slist.h"

/*
 * two sorts of emails are processed by this client: incoming and outgoing ones.
 * control flow is
 * email from internet > incoming > deliver > receipient receives mail
 * sender writes email > outgoing > mail > email sent through internet
 */
struct client
{
  char *name;
  NODE *outgoingBuffer;
  NODE *addressBook;
  char *autoResponse;
};

void outgoing (struct client *client, struct email *msg);

void incoming (struct client *client, struct email *msg);


struct addressBookEntry
{
  char *alias;
  NODE *address;
};

// TODO remove after fixing the composition-function-order-problem
void resolveAlias (struct client *client, struct email *msg);
void autoRespond (struct client *client, struct email *msg);

void sign (struct client *client, struct email *msg);
void decrypt (struct client *client, struct email *msg);
void encrypt (struct client *client, struct email *msg);
