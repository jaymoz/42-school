from config import *
from analytics import Research


def main():
    reader = Research(filename)
    observations = len(reader.data)
    heads, tails = reader.calc.count
    prob_head, prob_tails = reader.calc.fraction
    pred = reader.calc.predict_random(num_prediction)
    heads_pred, tails_pred = tuple(sum(elem) for elem in zip(*pred))
    text = template.format(
        observations,
        heads, tails,
        prob_head, prob_tails,
        num_prediction,
        heads_pred, tails_pred
        )
    reader.calc.save_file(text, result)


if __name__ == '__main__':
    main()