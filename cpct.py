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

        print(file_data)
        print("类型：", type(file_data))

        # 将字符串转化为字典或列表
        print("***转化yaml数据为字典或列表***")
        self.configs = yaml.load(file_data)
        print(self.configs)
        print("类型：", type(self.configs))

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
            template = template.replace("$" + key, value)

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
            print(self.format_pid + ".h" + "已存在，创建失败")
            return

        with open(self.format_pid + ".h", "w", encoding="utf-8") as fw:
            fw.write(result_h)

    def create_source_file(self):
        """
        创建源文件
        :return:
        """
        with open("./template.cpp", "r", encoding="utf-8") as fr:
            template_cpp = fr.read()

        result_cpp = self.replace_template_by_config(template_cpp)
        if os.path.exists(self.format_pid + ".cpp"):
            print(self.format_pid + ".cpp" + "已存在，创建失败")

        with open(self.format_pid + ".cpp", "w", encoding="utf-8") as fw:
            fw.write(result_cpp)

    def create_class(self):
        self.get_format_pid()
        self.read_config()
        self.add_other2config()
        self.create_header_file()
        self.create_source_file()


if __name__ == '__main__':
    # 输出用中文是为了防止乱码
    # id = (int)(input("请输入题号，纯数字就行，不需要前面补0\n"))
    # 如果命令行参数大于1即传入了题号从命令行获取题目id
    if len(sys.argv) > 1:
        pid = (int)(sys.argv[1])
    else:
        pid = (int)(input("请输入题号\n"))
    cpct = CPCT(pid)
    cpct.create_class()
