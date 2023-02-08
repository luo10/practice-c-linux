OBJS := main.o cmd_ls.o cmd_cp.o cmd_handle.o # 依赖文件
TARGET := tinyshell # 目标

$(TARGET):$(OBJS)
		@gcc $^ -o $@      # $^: 依赖的所有文件
		@echo "Done." 

%.o:%.c
		@gcc -c $< -o $@   # $<: 依赖的第一个文件   $@: 目标文件

clean:
		@rm *.o $(TARGET)
		@echo "Clean."
