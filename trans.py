'''
将本地代码转化为LeetCode的代码并复制到剪切板，方便直接提交
'''
import re
import os
import pyperclip
import sys

class Trans(object):
	"""代码转化类"""
	def __init__(self, id):
		super(Trans, self).__init__()
		self.id = id

	def id2filename(self):
		# 将数字转为P0001形式
		# 四位数字，左边补0
		filename = 'P{:0>4d}'.format(id)
		return filename

	def read_src(self, filename):
		'''
		.h与.c文件读取
		'''
		# 读取文件是否成功
		success = True
		# 头文件
		src_h = ""
		# 源文件
		src_c = ""
		try:
			with open(filename + '.h', 'r', encoding='utf-8') as hr:
				# print(hr.read())
				src_h = hr.read()
		except IOError:
			success = False
			print('Failed to open ' + filename + '.h')
		try:
			with open(filename + '.cpp', 'r', encoding='utf-8') as cr:
				src_c = cr.read()
		except IOError:
			success = False
			print('Failed to open ' + filename + '.c')
		return success, src_h, src_c

	def deal(self, src_h, src_c):
		'''
		具体处理函数
		'''
		# print(src_h)
		# print(src_c)

		# 替换#ifndef... #define
		src_h = re.sub(r'#ifndef.{2,30}_H\n#define.{2,30}_H\n', '', src_h)
		# 替换#endif...
		src_h = re.sub(r'#endif.{2,30}_H\n', '', src_h)
		# 将P0001形式的类名全部替换成Solution
		src_h = re.sub(r'P\d{4}', 'Solution', src_h)
		# 替换#include " " 和 #include < >  为空
		src_h = re.sub(r'#include {0,1}[\"<].{1,18}[\">]\n', '', src_h)
		# 替换override和继承
		src_h = src_h.replace('override', '')
		src_h = src_h.replace(': public Problem', ' ')
		# print(src_h)


		# 将P0001形式的类名全部替换成Solution
		src_c = re.sub(r'P\d{4}', 'Solution', src_c)
		# 替换#include " " 和 #include < >  为空
		src_c = re.sub(r'#include {0,1}[\"<].{1,18}[\">]\n', '', src_c)
		# print(src_c)

		return src_h + '\n' + src_c

	def run(self):
		filename = self.id2filename()
		success, src_h, src_c = self.read_src(filename)
		if success:
			desc = self.deal(src_h, src_c)
			# 复制到剪切板
			pyperclip.copy(desc)
		return success


if __name__ == '__main__':
	# 输出用中文是为了防止乱码
	# id = (int)(input("请输入题号，纯数字就行，不需要前面补0\n"))
	# 如果命令行参数大于1即传入了题号从命令行获取题目id
	if len(sys.argv) > 1:
		id = (int)(sys.argv[1])
	else:
		id = (int)(input("Please input problem id\n"))
	trans = Trans(id)
	success = trans.run()
	if success:
		print('The answer to ' + trans.id2filename() +' has been copied to the clipboard')
	else:
		print('Failed to generate answer to ' + trans.id2filename())
