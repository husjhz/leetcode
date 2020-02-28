#-*- coding:utf-8 -*-
import requests
from bs4 import BeautifulSoup
#import sys

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:57.0) Gecko/20100101 Firefox/57.0',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
}

def getMiddleStr(content, startStr, endStr): # 获取文本中间内容
    startIndex = content.index(startStr)
    if startIndex >= 0:
        startIndex += len(startStr)
        endIndex = content.index(endStr)
    return content[startIndex:endIndex]


def getCVES():  # 获取最新到CVE列表
    urls = []
    try:
        url = 'https://cassandra.cerias.purdue.edu/CVE_changes/today.html'
        res = requests.get(url, headers=headers, timeout=60)
        CVEList_html = getMiddleStr(res.text, 'New entries:', 'Graduations')
        soup = BeautifulSoup(CVEList_html, 'html.parser')
        for a in soup.find_all('a'):
            urls.append(a['href'])
        return urls
    except Exception as e:
        print(e)


def getCVEDetail(url):  # 获取CVE详情
    try:
        res = requests.get(url, headers=headers, timeout=60)
        soup = BeautifulSoup(res.text, 'html.parser')
        cveId = soup.find(nowrap='nowrap').find('h2').string
        table = soup.find(id='GeneratedTable').find('table')
        description = table.find_all('tr')[3].find('td').string
        print(cveId, end= " ")
        print(description)

    except Exception as e:
        print(e)

def getCVEDetailFromTotal():
    urls = getCVES()
    for url in urls:
        getCVEDetail(url)

def getCVEDetailFromFile():
    baseurl = "http://cve.mitre.org/cgi-bin/cvename.cgi?name="
    with open('cveid.txt', 'r') as f:
        while True:
            cveid = f.readline()
            if not cveid:
                break
            url = baseurl + cveid
            getCVEDetail(url)

def main():
    #getCVEDetailFromTotal()
    getCVEDetailFromFile()

if __name__ == '__main__':
    main()

