import sys

def ticker_symbols(ticker_symbol):
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
    val = {key:value for value, key in COMPANIES.items()}
    if ticker_symbol in val:
        return ("{} {}".format(val[ticker_symbol], STOCKS[ticker_symbol]))
    return 'Unknown ticker'
    


if __name__ == '__main__':
    if len(sys.argv) == 2:
        print(ticker_symbols(sys.argv[1].upper()))