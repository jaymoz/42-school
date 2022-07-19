import sys
import time

import requests
from bs4 import BeautifulSoup


def main(company, row):
    url = 'https://finance.yahoo.com/quote/{0}/financials?p={0}'
    header = {'user-agent': 'my-agent'}
    response = requests.get(url.format(company.lower()), headers=header)
    if not response or not response.url.endswith(company.lower()):
        raise requests.ConnectionError(f'No {company} company found')
    soup = BeautifulSoup(response.text, 'html.parser')
    result = list()
    result.append(row)
    if not soup.find(string=row):
        raise Exception(f'No {sys.argv[2]} found!')
    row = soup.find(string=row).parent
    col = row
    for i in range(5):
        result.append(col.find_next('span').string)
        col = result[-1]
    time.sleep(5)
    return tuple(result)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        raise AttributeError('Must be 2 arguments Ticker and rowam')
    ans = main(sys.argv[1], sys.argv[2])
    print(ans)