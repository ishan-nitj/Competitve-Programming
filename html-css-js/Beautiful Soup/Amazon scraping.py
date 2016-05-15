#soup=BeautifulSoup(open("an html document"))
#print type(soup)
#print soup.prettify()
#print soup.html.body.p
#print soup.html.body.contents[1]
#print soup.get_text()  shows the text as displayed on a webpage

##lst=soup.find_all('a') #list of links
##for link in lst:
##    print link.text,
##    print link.get("href")


#item
#item.text
#item.contents
#item.contents[1]
#item.contents[1].text

##print type(g_data)
##for item in g_data:
##    print item.contents[1].find_all("h2",{"class":"listingName"})[0].text
##

import requests
from bs4 import BeautifulSoup
r=requests.get('https://paytm.com/shop/search/?q=bottle&from=organic')
soup=BeautifulSoup(r.content)
g_data=soup.find_all("div",{"class":"grid-container"})
print g_data



##lst=g_data[0].contents
##print (lst[0].h2.text)
##for i in g_data[0].contents:
##    print i
##for item in g_data:
##    print item.contents
## 
