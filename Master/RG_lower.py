# 计算Petri网的可达图
# 作者：Li-Ning
# 日期：2023年12月3日
import numpy as np
import time
import math
start_time = time.perf_counter()

filename = 'post.txt'
filename1 = 'pre.txt'

# 使用numpy的loadtxt函数读取文件
data = np.loadtxt(filename, dtype=int)
data1 = np.loadtxt(filename1, dtype=int)


class System:  # Petri网(N, M0)
    def __init__(self):
        self.N_post = np.array(data1)  # 后置关联矩阵

        self.N_pre = np.array(data)  # 前置关联矩阵
        n = 100  # 长度
        m = 5  # 机器人数量
        arr = [0] * n
        if m > 0:
            step = math.ceil(n / m)
            for i in range(0, n, step):
                arr[i] = 1
        print(arr)
        self.M0 = np.array(arr)  # 初始状态
        self.N = self.N_pre - self.N_post  # 关联矩阵


M = list()  # 可达图
ARC = list()  # 可达图


sys = System()

visited_arrays = [sys.M0]  # 未访问的列表
M.append(sys.M0)  # 首先将初始状态M0加入可达状态集
rel = set()  # 禁忌表
rel.add(tuple(sys.M0))

while len(visited_arrays):  # 当未访问列表不为空
    M1 = visited_arrays[0]  # 取列表第一个未访问

    indices = []  # 记录可发射变迁
    for i in range(0, sys.N_post.shape[1]):  # 找到可发射的变迁
        boolean = np.all(M1.T >= sys.N_post[:, i])
        if boolean:
            indices.append(i)
    for i in indices:  # 对于每个变迁
        t = np.zeros((1, sys.N_post.shape[1]), dtype=int)
        t[0, i] = 1
        M_ = M1 + np.dot(sys.N, t.T).T  # 发射变迁得到新状态
        M_new = np.squeeze(M_)
        if tuple(M_new) in rel:
            ARC.append(i + 1)  # 记录变迁
        else:
            ARC.append(i + 1)  # 记录变迁
            M.append(M_new)  # 记录新状态
            rel.add(tuple(M_new))  # 新状态加入紧急表
            visited_arrays.append(M_new)  # 新状态加入待访问列表

    visited_arrays.pop(0)  # 已访问，删除

print(len(M))
print(len(ARC))
end_time = time.perf_counter()
# 在程序运行结束的位置添加结束时间
print("运行耗时", end_time - start_time)


