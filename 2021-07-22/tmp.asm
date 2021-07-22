0000000000001125 <sum>:
int sum(int n)
{
    1125:	55                   	push   %rbp
    1126:	48 89 e5             	mov    %rsp,%rbp
    1129:	48 83 ec 20          	sub    $0x20,%rsp
    112d:	89 7d ec             	mov    %edi,-0x14(%rbp)
    if (n == 0)
    1130:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
    1134:	75 07                	jne    113d <sum+0x18>
    {
        return 0;
    1136:	b8 00 00 00 00       	mov    $0x0,%eax
    113b:	eb 24                	jmp    1161 <sum+0x3c>
    }
    int a = n;
    113d:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1140:	89 45 fc             	mov    %eax,-0x4(%rbp)
    int b = sum(n - 1);
    1143:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1146:	83 e8 01             	sub    $0x1,%eax
    1149:	89 c7                	mov    %eax,%edi
    114b:	e8 d5 ff ff ff       	callq  1125 <sum>
    1150:	89 45 f8             	mov    %eax,-0x8(%rbp)
    int c = a + b;
    1153:	8b 55 fc             	mov    -0x4(%rbp),%edx
    1156:	8b 45 f8             	mov    -0x8(%rbp),%eax
    1159:	01 d0                	add    %edx,%eax
    115b:	89 45 f4             	mov    %eax,-0xc(%rbp)
    return c;
    115e:	8b 45 f4             	mov    -0xc(%rbp),%eax
}
    1161:	c9                   	leaveq 
    1162:	c3                   	retq   

0000000000001163 <main>:

int main()
{
    1163:	55                   	push   %rbp
    1164:	48 89 e5             	mov    %rsp,%rbp
    1167:	48 83 ec 10          	sub    $0x10,%rsp
    int a = sum(3);
    116b:	bf 03 00 00 00       	mov    $0x3,%edi
    1170:	e8 b0 ff ff ff       	callq  1125 <sum>
    1175:	89 45 fc             	mov    %eax,-0x4(%rbp)
    return 0;
    1178:	b8 00 00 00 00       	mov    $0x0,%eax
}
    117d:	c9                   	leaveq 
    117e:	c3                   	retq   
    117f:	90                   	nop
