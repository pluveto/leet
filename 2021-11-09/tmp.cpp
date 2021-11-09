bool Graph_DG::topological_sort() {
  cout << "图的拓扑序列为：" << endl;
  //栈s用于保存栈为空的顶点下标
  stack<int> s;
  int i;
  ArcNode *temp;
  //计算每个顶点的入度，保存在indgree数组中
  for (i = 0; i != this->vexnum; i++) {
    temp = this->arc[i].firstarc;
    while (temp) {
      ++this->indegree[temp->adjvex];
      temp = temp->next;
    }
  }

  //把入度为0的顶点入栈
  for (i = 0; i != this->vexnum; i++) {
    if (!indegree[i]) {
      s.push(i);
    }
  }
  // count用于计算输出的顶点个数
  int count = 0;
  while (!s.empty()) { //如果栈为空，则结束循环
    i = s.top();
    s.pop(); //保存栈顶元素，并且栈顶元素出栈
    cout << this->arc[i].data << " "; //输出拓扑序列
    temp = this->arc[i].firstarc;
    while (temp) {
      if (!(--this->indegree[temp->adjvex])) { //如果入度减少到为0，则入栈
        s.push(temp->adjvex);
      }
      temp = temp->next;
    }
    ++count;
  }
  if (count == this->vexnum) {
    cout << endl;
    return true;
  }
  cout << "此图有环，无拓扑序列" << endl;
  return false; //说明这个图有环
}