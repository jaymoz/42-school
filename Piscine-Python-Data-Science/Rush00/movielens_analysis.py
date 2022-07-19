import re
import collections
# from types import NoneType
from bs4 import BeautifulSoup
import requests
import datetime
from collections import Counter

def data_check(data):
    try:
        i = 0
        for line in data:
            if i == 0:
                if ' ' in line or '\t' in line:
                    raise ValueError("Incorrect data in the file")
                num_of_col = len(line.split(','))
            elif len(line.split(',')) < num_of_col:
                raise ValueError("Incorrect data in the file")
            i += 1
    except ValueError as err:
        print('\033[91mException!', err)

class Movies:
    """
    Analyzing data from movies.csv
    """
    def __init__(self, path_to_the_file):
        self.path = path_to_the_file
        self.data = list(self.file_generator())
        data_check(self.data)

    # generator object
    def file_generator(self):
        for line in open(self.path, "r"):
            yield line

    def dist_by_release(self):
        """
        The method returns a dict or an OrderedDict where the keys are years and the values are counts. 
        You need to extract years from the titles. Sort it by counts descendingly.
        """
        years = []
        for line in self.data:
            year = re.findall(r'\(\d{4}\)', line)
            if not year:
                year = re.findall(r'\(\d{4}\–\d{4}\)', line)
            if year:
                years.append(year[0][1:-1])
        x = dict(collections.Counter(years))
        release_years = {k: v for k, v in sorted(x.items(), key=lambda item: item[1], reverse=True)}
        return release_years
    
    def dist_by_genres(self):
        """
        The method returns a dict where the keys are genres and the values are counts.
        Sort it by counts descendingly.
        """
        all_genres = []
        for line in self.data:
            gen = line[line.rfind(',') + 1:-1]
            if gen and gen != 'genres':
                gens = gen.split('|')
                for genre in gens:
                    if genre != 'IMAX':
                        all_genres.append(genre)
        x = dict(collections.Counter(all_genres))
        genres = {k: v for k, v in sorted(x.items(), key=lambda item: item[1], reverse=True)}
        return genres
        
    def most_genres(self, n):
        """
        The method returns a dict with top-n movies where the keys are movie titles and 
        the values are the number of genres of the movie. Sort it by numbers descendingly.
        """
        n_movies = {}
        movies = {}
        for line in self.data:
            name = line[line.find(',') + 1 : line.rfind(',')]
            if name.rfind(" (") != -1:
                name = name[: name.rfind(" (")]
            gen = line[line.rfind(',') + 1:-1]
            if gen and gen != 'genres':
                gens = [genre for genre in gen.split('|') if genre != 'IMAX']
                n_movies[name] = len(gens)
        movies_list = collections.Counter(n_movies).most_common(n)
        for item in movies_list:
            movies[item[0]] = item[1]
        return movies

    def movie_id_title(self):
        id_title = {}
        for line in self.data:
            id = line[: line.find(',')]
            name = line[line.find(',') + 1 : line.rfind(',')]
            if name.rfind(" (") != -1:
                name = name[: name.rfind(" (")]
            if id != 'movieId':
                if name[0] != '\"':
                    id_title[id] = name
                else:
                    id_title[id] = name[1:]
        return id_title

class Links:
    """
    Analyzing data from links.csv
    """
    def __init__(self, path_to_the_file):
        self.path = path_to_the_file
        self.data = list(self.file_generator())
        data_check(self.data)
        self.m = Movies('ml-latest-small/movies.csv')
        self.movie_titles = self.m.movie_id_title()
    
    # generator object
    def file_generator(self):
        for line in open(self.path, "r"):
            yield line

    def all_movieIds(self):
        movieIds = []
        for line in self.data:
            movieId = line.split(',')[0]
            if movieId != 'movieId':
                movieIds.append(int(movieId))
        return movieIds

    def connect_to_server(self, imdbId):
        url = f'https://www.imdb.com/title/tt{imdbId}/'
        page = requests.get(url, headers={'User-Agent': 'Custom'})
        if page.status_code != 200:
            raise ValueError("URL doesn't exist")
        soup = BeautifulSoup(page.text, "html.parser")
        return soup

    def get_imdb(self, list_of_movies, list_of_fields):
        """
        The method returns a list of lists [movieId, field1, field2, field3, ...] for the list of movies given as the argument (movieId).
        For example, [movieId, Director, Budget, Cumulative Worldwide Gross, Runtime].
        The values should be parsed from the IMDB webpages of the movies.
        Sort it by movieId descendingly.
        """
        imdbIds = []
        imdb_info = []
        for movie in list_of_movies:
            for line in self.data:
                all_columns = line.split(',')
                if all_columns[0] != 'movieId' and movie == int(all_columns[0]):
                    imdbIds.append(all_columns[1])

        for i in range(len(list_of_movies)):
            movie_info = []
            soup = self.connect_to_server(str(imdbIds[i]))
            movie_info.append(list_of_movies[i])
            for field in list_of_fields:
                field = field.lower()
                if field == 'title':
                    title = soup.find('h1', attrs={"data-testid":"hero-title-block__title"})
                    if title:
                        title = title.text
                    movie_info.append(title)
                elif field == 'director':
                    director = soup.find('div', class_ = 'sc-fa02f843-0 fjLeDR')
                    if director:
                        director = director.li.a.text
                    movie_info.append(director)
                elif field == 'budget':
                    budget = soup.find('div', attrs={"data-testid":"title-boxoffice-section"})
                    if budget:
                        budget = budget.div.text
                    movie_info.append(budget)
                elif field == 'cumulative worldwide gross':
                    gross = soup.find('li', attrs={"data-testid":"title-boxoffice-cumulativeworldwidegross"})
                    if gross:
                        gross = gross.li.text
                    movie_info.append(gross)
                elif field == 'runtime':
                    runtime = soup.find('div', attrs={"data-testid":"title-techspecs-section"})
                    if runtime:
                        runtime = runtime.div.text
                    movie_info.append(runtime)
            imdb_info.append(movie_info)
        imdb_info = sorted(imdb_info, key=lambda x: x[0], reverse=True)
        return imdb_info

    """
    because the task is written poorly, i created addtional method
    to generae list of 20 random movies and get infrom from website
    coz parsing 10.000 pages from imdb is stupid and also impossible
    coz website blocks us at some point (yeah to ddos attacks!!)
    """
    def random_movies(self, n):
        from random import choices
        whole_list = self.all_movieIds()
        random_list = choices(whole_list, k=n)
        return random_list

        
    def top_directors(self, movie_list, n):
        """
        The method returns a dict with top-n directors where the keys are directors and 
        the values are numbers of movies created by them. Sort it by numbers descendingly.
        """
        whole_list = self.get_imdb(movie_list, ['director'])
        list_dir = [el[1] for el in whole_list]
        c = collections.Counter(list_dir).most_common(n)
        directors = dict(c)
        return directors
        
    def most_expensive(self, movie_list, n):
        """
        The method returns a dict with top-n movies where the keys are movie titles and
        the values are their budgets. Sort it by budgets descendingly.
        """
        whole_list = self.get_imdb(movie_list, ['budget'])
        for pos in whole_list:
            if pos and pos[1]:
                pos[1] = pos[1][:-12].replace(',', '')
        y = {}
        for k in whole_list:
            y[self.movie_titles[str(k[0])]] = k[1]
        with_budget = {}
        without_budget = {}
        for k, v in y.items():
            if v:
                with_budget[k] = v
            else:
                without_budget[k] = v
        sort_budgets = {k: v for k, v in sorted(with_budget.items(),
            key=lambda item: int(re.sub("[^0-9]", "", item[1])), reverse=True)}
        all_budgets = {**sort_budgets, **without_budget}
        budgets = dict(list(all_budgets.items())[:n])
        return budgets
        
    def most_profitable(self, movie_list, n):
        """
        The method returns a dict with top-n movies where the keys are movie titles and
        the values are the difference between cumulative worldwide gross and budget.
        Sort it by the difference descendingly.
        """
        whole_list = self.get_imdb(movie_list, ['budget', 'cumulative worldwide gross'])
        all_profits = {}
        for pos in whole_list:
            if pos[1] and pos[2]:
                title = self.movie_titles[str(pos[0])]
                profit = int(re.sub("[^0-9]", "", pos[2]))\
                    - int(re.sub("[^0-9]", "", pos[1]))
                all_profits[title] = profit
        sort_profits = {k: v for k, v in sorted(all_profits.items(),
            key=lambda item: item[1], reverse=True)}
        profits = dict(list(sort_profits.items())[:n])
        return profits
        
    def longest(self, movie_list, n):
        """
        The method returns a dict with top-n movies where the keys are movie titles and
        the values are their runtime. If there are more than one version â€“ choose any.
        Sort it by runtime descendingly.
        """
        whole_list = self.get_imdb(movie_list, ['runtime'])
        all_times = {}
        for info in whole_list:
            if info[1]:
                time_min = 0
                title = self.movie_titles[str(info[0])]
                t = info[1].split(' ')
                if len(t) == 4:
                    time_min = int(t[0]) * 60 + int(t[2])
                elif 'minutes' in info[1]:
                    time_min = int(re.sub("[^0-9]", "", info[1]))
                elif 'hour' in info[1]:
                    time_min = int(re.sub("[^0-9]", "", info[1])) * 60
                if time_min:
                    all_times[title] = time_min
        sort_times = {k: v for k, v in sorted(all_times.items(),
            key=lambda item: item[1], reverse=True)}
        all_runtimes = {}
        for k, v in sort_times.items():
            hour = v // 60
            min = v - hour * 60
            all_runtimes[k] = f"{hour}h {min}min"
        runtimes = dict(list(all_runtimes.items())[:n])
        return runtimes
        
    def top_cost_per_minute(self, movie_list, n):
        """
        The method returns a dict with top-n movies where the keys are movie titles and
        the values are the budgets divided by their runtime. The budgets can be in different currencies â€“ do not pay attention to it. 
        The values should be rounded to 2 decimals. Sort it by the division descendingly.
        """
        whole_list = self.get_imdb(movie_list, ['budget', 'runtime'])
        all_times = {}
        for info in whole_list:
            if info[1] and info[2]:
                time_min = 0
                title = self.movie_titles[str(info[0])]
                budget = int(re.sub("[^0-9]", "", info[1]))
                t = info[2].split(' ')
                if len(t) == 4:
                    time_min = int(t[0]) * 60 + int(t[2])
                elif 'minutes' in info[1]:
                    time_min = int(re.sub("[^0-9]", "", info[2]))
                elif 'hour' in info[1]:
                    time_min = int(re.sub("[^0-9]", "", info[2])) * 60
                if time_min:
                    all_times[title] = round(budget / time_min, 2)
        sort_costs = {k: v for k, v in sorted(all_times.items(),
            key=lambda item: item[1], reverse=True)}
        costs = dict(list(sort_costs.items())[:n])
        return costs

class Ratings:
    """
    Analyzing data from ratings.csv
    """
    def __init__(self, path_to_the_file):
        self.path = path_to_the_file
        self.data = list(self.file_generator())
        data_check(self.data)
        self.m = Movies('ml-latest-small/movies.csv')
        self.movie_titles = self.m.movie_id_title()

    def file_generator(self):
        for line in open(self.path, "r"):
            yield line

    class Movies:
        def __init__(self, ratings):
            self.ratings = ratings

        def dist_by_year(self):
            """
            The method returns a dict where the keys are years and the values are counts. 
            Sort it by years ascendingly. You need to extract years from timestamps.
            """
            years = []
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    l = line.split(',')
                    date = datetime.datetime.fromtimestamp(int(l[3]))
                    year = int(str(date)[:4])
                    years.append(year)
            x = dict(collections.Counter(years))
            ratings_by_year = {k: v for k, v in sorted(x.items(), key=lambda item: item[0])}
            return ratings_by_year
        
        def dist_by_rating(self):
            """
            The method returns a dict where the keys are ratings and the values are counts.
            Sort it by ratings ascendingly.
            """
            ratings = []
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    rating = line.split(',')[2]
                    ratings.append(rating)
            x = dict(collections.Counter(ratings))
            ratings_distribution = {float(k): v for k, v in sorted(x.items(), key=lambda item: item[0])}
            return ratings_distribution
        
        def top_by_num_of_ratings(self, n):
            """
            The method returns top-n movies by the number of ratings. 
            It is a dict where the keys are movie titles and the values are numbers.
            Sort it by numbers descendingly.
            """
            ids = []
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    ids.append(line.split(',')[1])
            x = dict(collections.Counter(ids))
            y = {}
            for k in x.keys():
                y[self.ratings.movie_titles[k]] = x[k]
            top_movies = dict(collections.Counter(y).most_common(n))
            return top_movies
        
        def median(self, lst):
            sortedLst = sorted(lst)
            lstLen = len(lst)
            index = (lstLen - 1) // 2
            if (lstLen % 2):
                return sortedLst[index]
            else:
                return (sortedLst[index] + sortedLst[index + 1])/2.0


        def top_by_ratings(self, n, metric='average'):
            """
            The method returns top-n movies by the average or median of the ratings.
            It is a dict where the keys are movie titles and the values are metric values.
            Sort it by metric descendingly.
            The values should be rounded to 2 decimals.
            """
            id_rates = []
            movies = {}
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    info = line.split(',')
                    id_rates.append((info[1], info[2]))
            id_rat_dict = collections.defaultdict(list)
            for i in range(len(id_rates)):
                id_rat_dict[id_rates[i][0]].append(float(id_rates[i][1]))
            if metric == 'average':
                for k, v in id_rat_dict.items():
                    movies[k] = round(sum(v) / len(v), 2)
            elif metric == 'median':
                for k, v in id_rat_dict.items():
                    movies[k] = round(self.median(v), 2)
            else:
                raise ValueError('No such metric')
            y = {}
            for k in movies.keys():
                y[self.ratings.movie_titles[k]] = movies[k]
            x = {k: v for k, v in sorted(y.items(), key=lambda item: item[1], reverse=True)}
            top_movies = dict(collections.Counter(x).most_common(n))
            return top_movies

        def variance(self, data):
            # Number of observations
            n = len(data)
            # Mean of the data
            mean = sum(data) / n
            # Square deviations
            deviations = [(x - mean) ** 2 for x in data]
            # Variance
            variance = sum(deviations) / n
            return variance
        
        def top_controversial(self, n):
            """
            The method returns top-n movies by the variance of the ratings.
            It is a dict where the keys are movie titles and the values are the variances.
            Sort it by variance descendingly.
            The values should be rounded to 2 decimals.
            """
            id_rates = []
            movies = {}
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    info = line.split(',')
                    id_rates.append((info[1], info[2]))
            id_rat_dict = collections.defaultdict(list)
            for i in range(len(id_rates)):
                id_rat_dict[id_rates[i][0]].append(float(id_rates[i][1]))
            for k, v in id_rat_dict.items():
                movies[k] = round(self.variance(v), 2)
            y = {}
            for k in movies.keys():
                y[self.ratings.movie_titles[k]] = movies[k]
            x = {k: v for k, v in sorted(y.items(), key=lambda item: item[1], reverse=True)}
            top_movies = dict(collections.Counter(x).most_common(n))
            return top_movies

    class Users(Movies):
        # In this class, three methods should work. 

        # The 1st returns the distribution of users by the number of ratings made by them.
        def user_num_of_ratings(self, n):
            ids = []
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    ids.append(line.split(',')[0])
            x = dict(collections.Counter(ids))
            top_users = dict(collections.Counter(x).most_common(n))
            return top_users
        
        # The 2nd returns the distribution of users by average or median ratings made by them.
        def user_by_ratings(self, n, metric='average'):
            id_rates = []
            users = {}
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    info = line.split(',')
                    id_rates.append((info[0], info[2]))
            id_rat_dict = collections.defaultdict(list)
            for i in range(len(id_rates)):
                id_rat_dict[id_rates[i][0]].append(float(id_rates[i][1]))
            if metric == 'average':
                for k, v in id_rat_dict.items():
                    users[k] = round(sum(v) / len(v), 2)
            elif metric == 'median':
                for k, v in id_rat_dict.items():
                    users[k] = round(self.median(v), 2)
            else:
                raise ValueError('No such metric')
            x = {k: v for k, v in sorted(users.items(), key=lambda item: item[1], reverse=True)}
            top_users = dict(collections.Counter(x).most_common(n))
            return top_users
        
        # The 3rd returns top-n users with the biggest variance of their ratings.
        def user_controversial(self, n):
            id_rates = []
            users = {}
            for line in self.ratings.data:
                if line != 'userId,movieId,rating,timestamp\n':
                    info = line.split(',')
                    id_rates.append((info[0], info[2]))
            id_rat_dict = collections.defaultdict(list)
            for i in range(len(id_rates)):
                id_rat_dict[id_rates[i][0]].append(float(id_rates[i][1]))
            for k, v in id_rat_dict.items():
                users[k] = round(self.variance(v), 2)
            x = {k: v for k, v in sorted(users.items(), key=lambda item: item[1], reverse=True)}
            top_users = dict(collections.Counter(x).most_common(n))
            return top_users

        # Inherit from the class Movies. Several methods are similar to the methods from it.

class Tags:
    """
    Analyzing data from tags.csv
    """

    def __init__(self, path_to_the_file):
        self.filename = path_to_the_file
        self.data = list(self.file_gen())
        data_check(self.data)
        """
        Put here any fields that you think you will need.
        """

    def file_gen(self):
        for line in open(self.filename, "r"):
            yield line

    def get_open_csv(self):
        with open(self.filename) as fd:
            next(fd)
            for row in fd:
                yield row.strip()

    def file_generator(self):
        for line in self.get_open_csv():
            line_dict = {}

            arr = line.strip('\n').split(",")
            for obj in arr:
                line_dict['userId'] = arr[0]
                line_dict['movieId'] = arr[1]
                line_dict['tag'] = arr[2]
                line_dict['timestamp'] = arr[3]
            yield line_dict

    def load_data(self):
        for tags in self.file_generator():
            tags['tag'] = tags['tag'].lower()
            yield tags

    def most_words(self, n):
        """
        The method returns top-n tags with most words inside. It is a dict 
        where the keys are tags and the values are the number of words inside the tag.
        Drop the duplicates. Sort it by numbers descendingly.
        """
        big_tags = Counter()
        for line in self.load_data():
            tag = line['tag'].split(' ')
            big_tags[" ".join(tag)] = len(tag)
        res = big_tags.most_common(n)
        return dict(res)

    def longest(self, n):
        """
        The method returns top-n longest tags in terms of the number of characters.
        It is a list of the tags. Drop the duplicates. Sort it by numbers descendingly.
        """
        big_tags = Counter()
        for line in self.load_data():
            for tag in line['tag'].split(' '):
                big_tags[tag] = len(tag)
        res = dict(big_tags.most_common(n)).keys()
        return list(res)

    def most_words_and_longest(self, n):
        """
        The method returns the intersection between top-n tags with most words inside and 
        top-n longest tags in terms of the number of characters.
        Drop the duplicates. It is a list of the tags.
        """
        return list(set(self.most_words(n)).intersection(set(self.longest(n))))
        
    def most_popular(self, n):
        """
        The method returns the most popular tags. 
        It is a dict where the keys are tags and the values are the counts.
        Drop the duplicates. Sort it by counts descendingly.
        """
        big_tags = Counter()
        for line in self.load_data():
            for tag in line['tag'].split(' '):
                if tag not in big_tags:
                    big_tags[tag] = 0
                big_tags[tag] += 1
        popular_tags = dict(big_tags.most_common(n))
        return popular_tags
        
    def tags_with(self, word):
        """
        The method returns all unique tags that include the word given as the argument.
        Drop the duplicates. It is a list of the tags. Sort it by tag names alphabetically.
        """
        word = str(word).lower()
        res = set()
        for line in self.load_data():
            tag = line['tag']
            for each in tag.split(" "):
                if each == word:
                    res.add(str(tag))
        return sorted(res)

class Tests:
    def setup_class(self):
        self.tags = Tags("ml-latest-small/tags.csv")
        self.movies = Movies('ml-latest-small/movies.csv')
        self.ratings = Ratings('ml-latest-small/ratings.csv')
        self.links = Links('ml-latest-small/links.csv')
        self.movie_list = movie_list = [1, 100, 27912, 32743, 45672, 111795, 173317, 193583]
        self.list_of_fields = ['movieId', 'Director', 'Budget', 'Cumulative Worldwide Gross', 'Runtime']


    # ______________________________________


    # Test for Movies class
    # ______________________________________
    def test_0_file_generator(self):
        assert str(type(self.movies.file_generator())) == "<class 'generator'>"

    def test_1_file_generator(self):
        for line in self.movies.file_generator():
            assert type(line) == type('')

    def test_0_dist_by_release(self):
        assert type(self.movies.dist_by_release()) == type({})

    def test_1_dist_by_release(self):
        for k,v in self.movies.dist_by_release().items():
            assert type(k) == type('') and type(v) == type(1)

    def test_2_dist_by_release(self):
        assert self.movies.dist_by_release() == {k: v for k, v in 
            sorted(self.movies.dist_by_release().items(), key=lambda item: item[1], reverse=True)}

    def test_0_dist_by_genres(self):
        assert type(self.movies.dist_by_genres()) == type({})

    def test_1_dist_by_genres(self):
        for k,v in self.movies.dist_by_genres().items():
            assert type(k) == type('') and type(v) == type(1)

    def test_2_dist_by_genres(self):
        assert self.movies.dist_by_genres() == {k: v for k, v in 
            sorted(self.movies.dist_by_genres().items(), key=lambda item: item[1], reverse=True)}

    def test_0_most_genres(self):
        assert type(self.movies.most_genres(5)) == type({})

    def test_1_most_genres(self):
        for k,v in self.movies.most_genres(5).items():
            assert type(k) == type('') and type(v) == type(1)

    def test_2_most_genres(self):
        assert self.movies.most_genres(5) == dict(collections.Counter(self.movies.most_genres(5)))

    def test_0_movie_id_title(self):
        assert type(self.movies.movie_id_title()) == type({})

    def test_1_movie_id_title(self):
        for k,v in self.movies.movie_id_title().items():
            assert type(k) == type('') and type(v) == type('')
    # ______________________________________


    # Test for Links class
    # ______________________________________
    def test_0_file_generator(self):
        assert str(type(self.links.file_generator())) == "<class 'generator'>"

    def test_1_file_generator(self):
        for line in self.links.file_generator():
            assert type(line) == type('')

    def test_0_all_movieIds(self):
            assert type(self.links.all_movieIds()) == type([])

    def test_1_all_movieIdsr(self):
        for line in self.links.all_movieIds():
            assert type(line) == type(4)

    def test_connect_to_server(self):
        assert str(type(self.links.connect_to_server('0113228'))) == "<class 'bs4.BeautifulSoup'>"

    def test_0_get_imdb(self):
        assert type(self.links.get_imdb(self.movie_list, self.list_of_fields)) == type([])

    def test_1_get_imdb(self):
        for line in self.links.get_imdb(self.movie_list, self.list_of_fields):
            assert type(line) == type([])

    def test_2_get_imdb(self):
        x = self.links.get_imdb(self.movie_list, self.list_of_fields)
        assert x == sorted(x, key=lambda x: x[0], reverse=True)

    def test_random_movies(self):
        assert type(self.links.random_movies(2)) == type([])

    def test_0_top_directors(self):
        assert type(self.links.top_directors(self.movie_list, 2)) == type({})

    def test_1_top_directors(self):
        for k,v in self.links.top_directors(self.movie_list, 2).items():
            assert type(k) == type('') and type(v) == type(4)

    def test_2_top_directors(self):
        x = self.links.top_directors(self.movie_list, 5)
        assert x == dict(collections.Counter(x))

    def test_0_most_expensive(self):
        assert type(self.links.most_expensive(self.movie_list, 2)) == type({})

    def test_1_most_expensive(self):
        for k,v in self.links.most_expensive(self.movie_list, 2).items():
            assert type(k) == type('') and (type(v) == type('') or type(None))

    def test_2_most_expensive(self):
        x = self.links.most_expensive(self.movie_list, 5)
        assert x == dict(collections.Counter(x))

    def test_0_most_profitable(self):
        assert type(self.links.most_profitable(self.movie_list, 2)) == type({})

    def test_1_most_profitable(self):
        for k,v in self.links.most_profitable(self.movie_list, 2).items():
            assert type(k) == type('') and (type(v) == type(4) or type(None))

    def test_2_most_profitable(self):
        x = self.links.most_profitable(self.movie_list, 5)
        assert x == dict(collections.Counter(x))

    def test_0_longest(self):
        assert type(self.links.longest(self.movie_list, 2)) == type({})

    def test_1_longest(self):
        for k,v in self.links.longest(self.movie_list, 2).items():
            assert type(k) == type('') and (type(v) == type('') or type(None))

    def test_2_longest(self):
        x = self.links.longest(self.movie_list, 5)
        assert x == dict(collections.Counter(x))

    def test_0_top_cost_per_minute(self):
        assert type(self.links.top_cost_per_minute(self.movie_list, 2)) == type({})

    def test_1_top_cost_per_minute(self):
        for k,v in self.links.top_cost_per_minute(self.movie_list, 2).items():
            assert type(k) == type('') and (type(v) == type(4.2) or type(None))

    def test_2_top_cost_per_minute(self):
        x = self.links.top_cost_per_minute(self.movie_list, 5)
        assert x == dict(collections.Counter(x))
    # ______________________________________
    # ______________________________________


    # Test for Tags class
    # ______________________________________
    def test_tags_with(self):
        result = self.tags.tags_with('Horror')
        assert (isinstance(result, list) and
                set(map(type, result)) == {str} and
                sorted(result, reverse=False) == list(result))
            
    def test_tags_most_words(self):
        result = self.tags.most_words(10)
        for key,value in result.items():
            assert(isinstance(key, str) and isinstance(value, int))
        assert(sorted(result.values(), reverse=True) == list(result.values()))

    def test_tags_most_words_and_longest(self):
        result = self.tags.most_words_and_longest(1000)
        assert (isinstance(result, list) and
                set(map(type, result)) == {str})
    def test_tags_most_popular(self):
        result = self.tags.most_popular(10)
        assert (isinstance(result, dict) and
                (set(map(type, result.values())) == {int} and
                 set(map(type, result.keys())) == {str}) and
                sorted(result.values(), reverse=True) == list(result.values()))

    def test_tags_longest(self):
        result = self.tags.longest(10)
        for each in result:
            assert(isinstance(each, str))
        assert(isinstance(result, list))

    # ______________________________________


    # Test for Ratings class
    # ______________________________________
    def test_rating_dist_by_year(self):
        r = self.ratings.Movies(self.ratings)
        result = r.dist_by_year()
        for key, value in result.items():
            assert(isinstance(key, int) and isinstance(value, int) and isinstance(result, dict))

    def test_rating_dist_by_rating(self):
        r = self.ratings.Movies(self.ratings)
        result = r.dist_by_rating()
        for key, value in result.items():
                assert(isinstance(key, float) and isinstance(value, int) and isinstance(result, dict))

    def test_rating_top_by_num_of_ratings(self):
        r = self.ratings.Movies(self.ratings)
        result = r.top_by_num_of_ratings(10)
        for key, value in result.items():
                assert(isinstance(key, str) and isinstance(value, int) and isinstance(result, dict))
    
    
    def test_rating_top_by_ratings(self):
        for metric in ['average', 'median']:
            r = self.ratings.Movies(self.ratings)
            result = r.top_by_ratings(500, metric)
            for key, value in result.items():
                assert(isinstance(key, str) and isinstance(value, float) 
                 and isinstance(result, dict))


    def test_rating_top_controversial(self):
        r = self.ratings.Movies(self.ratings)
        result = r.top_controversial(10)

        for key, value in result.items():
                assert(isinstance(key, str) and isinstance(value, float) 
                 and isinstance(result, dict))
        sorted(result.values(), reverse=False) == list(result.values())


    def test_user_num_of_ratings(self):
        r = self.ratings.Users(self.ratings)
        result = r.user_num_of_ratings(100)
        for key, value in result.items():
            assert(isinstance(key, str) and isinstance(value, int) 
                 and isinstance(result, dict))

    def test_user_by_ratings(self):
        r = self.ratings.Users(self.ratings)
        result = r.user_by_ratings(100)
        for key, value in result.items():
            assert(isinstance(key, str) and isinstance(value, float) 
                 and isinstance(result, dict))

    def test_user_controversial(self):
        r = self.ratings.Users(self.ratings)
        result = r.user_controversial(100)
        for key, value in result.items():
            assert(isinstance(key, str) and isinstance(value, float) 
                 and isinstance(result, dict))
        assert(sorted(result.values(), reverse=True) == list(result.values()))