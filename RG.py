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
    def __init__(self):        # 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18
        self.N_post = np.array([[1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                                [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0],
                                [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]])  # 后置关联矩阵
        self.N_pre = np.array([[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0],
                               [0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
                               [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                               [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1]])  # 前置关联矩阵

        self.N = self.N_pre - self.N_post  # 关联矩阵

        self.M0 = np.array([4, 4, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])  # 初始状态
        self.M_End = np.array([0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4])  # 结束状态

        self.t_label = np.array([0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1])  # 可观变迁：1不可观变迁：0

        self.P_resources = np.array([0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])  # 资源库所
        self.P_activity = np.array([0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0])  # 活动库所
        self.P_buffer = np.array([0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0])  # 缓冲库所

        self.Time = np.array([0, 0, 0, 0, 0, 4, 3, 0, 3, 2, 4, 2, 0, 3, 4, 4, 0, 0])  # 时间标签
        self.Mac = [[], [], [], [], [], [1, 1, 2], [1, 1, 1], [], [1, 2, 2], [1, 2, 3], [2, 1, 1], [2, 1, 3],
                    [], [2, 2, 1], [2, 2, 2], [2, 2, 3], []]  # 机器标签--> [1, 1, 2]：工件1工序1机器2

        self.H_time = np.array([5, 5, 0, 0, 0, 2, 2, 2, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0])


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
            ARC.append(M1)
            ARC.append(i + 1)  # 记录变迁
            ARC.append(M_new)
        else:
            ARC.append(M1)
            ARC.append(i + 1)  # 记录变迁
            ARC.append(M_new)
            M.append(M_new)  # 记录新状态
            rel.add(tuple(M_new))  # 新状态加入紧急表
            visited_arrays.append(M_new)  # 新状态加入待访问列表

    visited_arrays.pop(0)  # 已访问，删除

print(len(M))
print(len(ARC)/3)
end_time = time.perf_counter()
# 在程序运行结束的位置添加结束时间
print("运行耗时", end_time - start_time)

