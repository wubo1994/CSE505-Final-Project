startcocooserver:	api.so	api.h
	swipl -o dialog -c lazy_streams.pl
	gcc-9 api.so -static-libgcc -o startcoocoserver
api.so:
	swipl-ld -shared -o api -goal true api.c lazy_streams.pl -DLIKES_EXPORTS -v
clean:
	rm -rf dialog
	rm -rf startcoocoserver
	rm -rf api.so
