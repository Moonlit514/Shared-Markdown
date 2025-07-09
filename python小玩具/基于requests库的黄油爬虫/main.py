import os
try :import requests
except ImportError:
    print("缺少requests模块，正在安装...")
    os.system("pip install requests")
try :import bs4
except ImportError:
    print("缺少bs4模块，正在安装...")
    os.system("pip install bs4")
try :import pandas as pd
except ImportError:
    print("缺少pandas模块，正在安装...")
    os.system("pip install pandas")

dictionary = {}
m = input("要爬取几页/285页：（记得挂梯）")
for i in range(int(m)):
    print(f"正在爬取中..."+int((i+1)/int(m)*20)*"●"+(20-int((i+1)/int(m)*20))*"○"+"%.2f"%((i+1)/int(m)*100)+"%",end="\r")
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'
    }
    response = requests.get(f'https://www.acggw.one/game/page/{i+1}', headers=headers)
    response.encoding = 'utf-8'  # 确保正确的编码

    res=bs4.BeautifulSoup(response.text, 'html.parser')
    https_urls = [a['href'] for a in res.find_all('a', href=True) if a['href'].startswith('https')]
    https_urls = list(set(https_urls))
    filtered_res = []
    for i in https_urls:
        if i[-4:]=='html' :

            filtered_res.append(i)
  
    keystr = ""
    valuestr = ""
    value=[]
    for url in filtered_res:
        response2 = requests.get(url)
        response2.encoding = 'utf-8'  # 确保正确的编码
        res2 = bs4.BeautifulSoup(response2.text, 'html.parser')
        
 
        text = res2.get_text()
        start_index = text.find("【")
        end_index = text.find("港湾")
        
        if start_index != -1 and end_index != -1 and start_index < end_index:
            
            keystr = text[start_index:end_index + len("港湾")]
             
        
        start_index2 = text.find("链接")
        end_index2 = text.find("解压码")
        
        if start_index2 != -1 and end_index2 != -1 and start_index2 < end_index2:
            valuestr  = text[start_index2:end_index2 + len("三次郎")] +":三次郎"
            value=valuestr.split("\n")
            if '\xa0' in value:
                value.remove('\xa0')

        dictionary[keystr] = value
data_1 = []
for key, value in dictionary.items():
    combolist = [key]+value
    data_1.append(combolist)

# 确保所有行的长度一致
max_length = max(len(row) for row in data_1)
for row in data_1:
    if len(row) < max_length:
        row.extend([''] * (max_length - len(row)))

# 动态生成列名
columns = ["游戏名称"] + [f"游戏链接{i+1}" for i in range(max_length - 1)]
df = pd.DataFrame(data_1, columns=columns)
df.to_excel('ygames.xlsx', index=False)
print("正在爬取中..."+20*"●"+"100.00%",end="\n")
print("放在ygames.xlsx了，注意身体哦",end="\n")
print("ps:提取码的顺序与给出的网址顺序一致",end="\n")

    
