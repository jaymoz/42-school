import sys

def stock_prices(company):
    COMPANIES = {
        'Apple': 'AAPL',
        'Microsoft': 'MSFT',
        'Netflix': 'NFLX',
        'Tesla': 'TSLA',
        'Nokia': 'NOK'
        }
    STOCKS = {
        'AAPL': 287.73,
        'MSFT': 173.79,
        'NFLX': 416.90,
        'TSLA': 724.88,
        'NOK': 3.37
        }
    if company in COMPANIES:
        return STOCKS[COMPANIES[company]]
    return 'Unknown company'
    


if __name__ == '__main__':
    if len(sys.argv) == 2:
        print(stock_prices(sys.argv[1].lower().capitalize()))