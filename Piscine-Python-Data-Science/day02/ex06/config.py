filename = 'data.csv'
num_prediction = 3
template = """Report
We have made {} observations from tossing a coin: {} of them were tails and {} of
them were heads. The probabilities are {:.2f}% and {:.2f}%, respectively. Our
forecast is that in the next {} observations we will have: {} tail and {} heads.
"""
result = 'report'
log_format = '%(asctime)-15s %(message)s'
webhook_url = None
success = "The report has been successfully created"
failure = "The report hasn’t been created due to an error"
log_output="analytics.log"