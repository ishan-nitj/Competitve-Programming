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

import requests
from bs4 import BeautifulSoup
r=requests.get('http://mumbai.yellowpages.co.in/coffee')
soup=BeautifulSoup(r.content)


#item
#item.text
#item.contents
#item.contents[1]
#item.contents[1].text

g_data=soup.find_all("div",{"class":"header2 clearfix"})
print type(g_data)

##print type(g_data)
##for item in g_data:
##    print item.contents[1].find_all("h2",{"class":"listingName"})[0].text
##
