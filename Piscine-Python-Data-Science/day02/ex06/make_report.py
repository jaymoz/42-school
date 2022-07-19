from config import *
from analytics import Research
import logging


def main():
    try:
        logging.info("reading input file")
        reader = Research(filename)
        observations = len(reader.data)
        logging.info("calculating the count of heads and tails")
        heads, tails = reader.calc.count
        logging.info("calculates fractions in percents")
        prob_head, prob_tails = reader.calc.fraction
        logging.info("calculating lists of predicted observations of heads and tails")
        pred = reader.calc.predict_random(num_prediction)
        heads_pred, tails_pred = tuple(sum(elem) for elem in zip(*pred))
        text = template.format(
            observations,
            heads, tails,
            prob_head, prob_tails,
            num_prediction,
            heads_pred, tails_pred
            )
        logging.info(f"saving result of analysis inside {result}.txt")
        reader.calc.save_file(text, result)
        logging.info("sending message to slack")
        reader.send_message_to_slack(success, webhook_url=webhook_url)
    except Exception:
        reader.send_message_to_slack(failure, webhook_url=webhook_url)

if __name__ == '__main__':
    logging.basicConfig(format=log_format, level=logging.NOTSET,filemode="w",filename=log_output)
    main()