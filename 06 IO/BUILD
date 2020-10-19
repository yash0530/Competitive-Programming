{
 "cmd":["bash", "-c", "g++ -std=c++14 '${file}' && ./a.out < '/home/yash/Documents/CP/06 IO/input.txt' > '/home/yash/Documents/CP/06 IO/output.txt'"],
 "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
 "working_dir": "${file_path}",
 "selector": "source.c, source.c++",
 "variants":
 [
   {
     "name": "Run",
     "cmd":["bash", "-c", "g++ -std=c++14 '${file}' -o '${file_path}/${file_base_name}' && '${file_path}/${file_base_name}'"]
   }
 ]
}