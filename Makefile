CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

app.out: *.cc *.hpp
	g++ $(CFLAGS) -o app.out *.cc $(LDFLAGS)

.PHONY: test clean

test: app.out
	./app.out

clean:
	rm -f app.out
