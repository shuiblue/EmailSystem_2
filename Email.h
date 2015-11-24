struct email
{
  int id;
  char *from;
  char *to;
  char *subject;
  char *body;
  int isSigned;
  char *signKey;
};

struct email *cloneEmail (struct email *msg);

void printMail (struct email *msg);

int isReadable (struct email *msg);

int isSigned (struct email *msg);
