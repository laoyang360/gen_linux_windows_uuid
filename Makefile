gen_uuid:
	g++ gen_uuid.cpp -o gen_uuid -luuid
clean:
	rm -rf gen_uuid
