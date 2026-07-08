CFLAGS = -I.
LIBS = -lm
NAME = main
ODIR = .
OBJ = o

OBJS = KarpRabin.$(OBJ) \
	main.$(OBJ)

OBJECTS = $(patsubst %,$(ODIR)/%,$(OBJS))
VPATH = .

$(ODIR)/%.$(OBJ): %.c
	@test -d $(ODIR) || mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(ODIR)/$(NAME) $(OBJECTS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(ODIR)/$(NAME) $(OBJECTS)