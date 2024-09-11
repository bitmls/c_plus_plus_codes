#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define    MAXN 100
#define INF 0x3f3f3f3f

int a[MAXN][MAXN];    //�洢ͼ
int dist[MAXN], vis[MAXN];    //dist[]�㵽��ǰ��ľ���, vis[]�����ж��Ƿ��߹���ǰ·��
vector<int> pre[MAXN];    //�洢ǰ�����
vector<int> ans; //���ڴ洢���·��
int n, m, s, t;    //n����㣬m���ߣ�s��Դ��, tΪĿ���

struct NodeType {
    int vno;
    int length;
    bool operator<(const NodeType& e) const
    {
        return length > e.length;    //lengthԽСԽ���ȳ���
    }
};

void Init()
{
    int x, y, len;
    cout << "�����������������������Դ�㡢Ŀ���" << endl;
    cin >> n >> m >> s >> t;
    memset(dist, INF, sizeof(dist));
    memset(a, INF, sizeof(a));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++)    //��ͼ--����ͼ
    {
        cin >> x >> y >> len;
        a[x][y] = len;
    }
}

void bfs()
{
    NodeType e, e1;
    queue<NodeType> pqu;
    e.vno = s;
    e.length = 0;
    pqu.push(e);
    dist[s] = 0;

    while (!pqu.empty())
    {
        e = pqu.front();
        pqu.pop();
        for (int j = 0; j < n; j++)
        {
            if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j] && !vis[j])
            {    //��֦��e.vno������j�б߲���·�����ȸ���
                dist[j] = e.length + a[e.vno][j];
                pre[j].clear();
                pre[j].push_back(e.vno);
                e1.vno = j;    //�������ڵ�j�Ľ��e1
                e1.length = dist[j];
                pqu.push(e1);
            }
            else if (a[e.vno][j] < INF && e.length + a[e.vno][j] == dist[j] && !vis[j])
            {
                pre[j].push_back(e.vno);
                e1.vno = j;    //�������ڵ�j�Ľ��e1
                e1.length = dist[j];
                pqu.push(e1);
            }
        }

    }

}

void OutPutPath(int i)
{
    for (int j = 0; j < pre[i].size(); j++)
    {
        ans.push_back(pre[i][j]);
        if (pre[i][j] == s)
        {
            for (int k = ans.size() - 1; k >= 0; k--)
            {
                cout << ans[k] << " ";
            }
            cout << "\n";
        }
        OutPutPath(pre[i][j]);    //����һ��
        ans.pop_back();    //ɾ���ϸ�Ԫ��
    }
}

void OutPut()
{
    cout << "��" << s << "��" << t << "����̾�����" << dist[t] << endl;
    cout << "·��Ϊ��";
    OutPutPath(t);
}

int main()
{
    Init();
    bfs();
    ans.push_back(t);
    OutPut();
    return 0;
}
/*
6 8 0 5
0 2 10
0 4 30
0 5 60
2 3 50
4 3 20
4 5 60
3 5 10
1 2 4
*/

/*
7 11 0 6
0 1 2
0 2 8
0 3 5
1 2 3
1 4 3
2 5 4
3 5 6
3 6 9
4 5 5
4 6 7
5 6 2
*/