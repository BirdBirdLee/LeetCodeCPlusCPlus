import re
import os
import sys
import yaml
import time


class CPCT(object):
    """
    输入题号，创建.cpp和.h模板文件
    cpct即createProblemClassTemplate
    """

    def __init__(self, pid):
        self.pid = pid
        self.format_pid = None
        self.configs = None

    def read_config(self):
        """
        读取配置
        :return:
        """
        yaml_file = "./config.yaml"
        file = open(yaml_file, 'r', encoding="utf-8")
        file_data = file.read()
        file.close()

        # print(file_data)
        # print("类型：", type(file_data))

        # 将字符串转化为字典或列表
        # print("***转化yaml数据为字典或列表***")
        self.configs = yaml.load(file_data)
        # print(self.configs)
        # print("类型：", type(self.configs))

    def add_other2config(self):
        # 把题目号暂时加到配置里面，方便替换
        self.configs['pid'] = self.format_pid

        self.configs['date'] = time.strftime("%Y/%m/%d")
        self.configs['time'] = time.strftime("%H:%M")

    def get_format_pid(self):
        """
        生成格式化的pid,字符型
        :return:
        """
        self.format_pid = 'P{:0>4d}'.format(self.pid)

    def replace_template_by_config(self, template):
        for key, value in self.configs.items():
            # print("$" + key, value)
            template = template.replace("$" + key, str(value))

        return template

    def create_header_file(self):
        """
        创建头文件
        :return:
        """
        with open("./template.h", "r", encoding="utf-8") as fr:
            template_h = fr.read()

        result_h = self.replace_template_by_config(template_h)
        if os.path.exists(self.format_pid + ".h"):
            print("Failed to create " + self.format_pid + ".h" + ", detail" + self.format_pid + ".h already exists")
            return

        with open(self.format_pid + ".h", "w", encoding="utf-8") as fw:
            fw.write(result_h)
            print("Successfully created " + self.format_pid + ".h")

    def create_source_file(self):
        """
        创建源文件
        :return:
        """
        with open("./template.cpp", "r", encoding="utf-8") as fr:
            template_cpp = fr.read()

        result_cpp = self.replace_template_by_config(template_cpp)
        if os.path.exists(self.format_pid + ".cpp"):
            print("Failed to create " + self.format_pid + ".cpp" + ", detail" + self.format_pid + ".cpp already exists")
            return

        with open(self.format_pid + ".cpp", "w", encoding="utf-8") as fw:
            fw.write(result_cpp)
            print("Successfully created " + self.format_pid + ".cpp")

    def edit_pid_in_main_cpp(self):
        """
        修改main.cpp中的题号
        :return:
        """
        if self.configs['editMain'] == 'False':
            return
        with open("./main.cpp", "r", encoding="utf-8") as fr:
            main_cpp_origin = fr.read()
        main_cpp_dealt = re.sub(r'[0-9]{4}', '{:0>4d}'.format(self.pid), main_cpp_origin)
        with open("./main.cpp", "w", encoding="utf-8") as fw:
            fw.write(main_cpp_dealt)
        print("Successfully edited " + "main.cpp")

    def edit_CMake(self):
        """
        修改Cmake
        :return:
        """
        CMake_filename = "CMakeLists.txt"
        if self.configs['CMake'] == 'False':
            return
        with open(CMake_filename, "r", encoding="utf-8") as fr:
            CMake_origin = fr.read()
        # 清除原来Cmake中的.h和.cpp声明
        CMake_dealt = CMake_origin.replace(self.format_pid + ".h", " ")
        CMake_dealt = CMake_dealt.replace(self.format_pid + ".cpp", " ")
        # 注意这里用正则实现更好
        # 匹配 add_executable
        # 在结尾加上.h和.cpp声明
        CMake_dealt = CMake_dealt.strip()[:-1] + " " + self.format_pid + ".h " + self.format_pid + ".cpp)"
        # print(CMake_dealt)
        with open(CMake_filename, "w", encoding="utf-8") as fw:
            fw.write(CMake_dealt)
        print("Successfully edited " + CMake_filename)

    def create_class(self):
        self.get_format_pid()
        self.read_config()
        self.add_other2config()
        self.create_header_file()
        self.create_source_file()
        self.edit_pid_in_main_cpp()
        self.edit_CMake()


if __name__ == '__main__':
    # 输出用英文是为了防止乱码
    # id = (int)(input("请输入题号，纯数字就行，不需要前面补0\n"))
    # 如果命令行参数大于1即传入了题号从命令行获取题目id
    if len(sys.argv) > 1:
        pid = (int)(sys.argv[1])
    else:
        pid = (int)(input("Please input problem id\n"))
    cpct = CPCT(pid)
    cpct.create_class()
