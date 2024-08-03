# Variáveis do compilador
CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99
TARGET = poketrunfo

# Arquivos fonte e objetos
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets para evitar conflitos com arquivos
.PHONY: all clean
