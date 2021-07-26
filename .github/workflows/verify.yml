from onlinejudge_verify.online_submission.submissions import *
from requests import session
import requests
import mechanize
from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import Select
from selenium.webdriver.chrome.options import Options

import time
import json
import traceback

class VJudge:
    JUDGE_NAME = "vjudge"
    JUDGE_URL = "https://vjudge.net/"
    PROBLEM_URL = "https://vjudge.net/problem/"
    GOOD_VERDICTS = ["Accepted"]
    BAD_VERDICTS = ["Time", "Wrong", "Compilation", "Runtime", "Memory", "Output", "Presentation", "Compile", "Unknown"]

    LANGUAGES = {
        "C" : "43", #GNU GCC C11 5.1.0
        "java" : "36", # Java 1.8.0_241
        "cpp" : "61", # 
        "C++" : "C++", # C++ 17 64 bit
        "py" : "41" #PyPy 3.6 (7.2.0)
    }

    JUDGE_PREFIX = {
        "codeforces" : "CodeForces",
        "atcoder" : "AtCoder",
        "spoj" : "SPOJ",
        "kattis" : "Kattis"
    }

    JUDGE_MARKER = {
        "codeforces.com" : "codeforces",
        "atcoder.jp" : "atcoder",
        "spoj.com" : "spoj",
        "open.kattis.com" : "kattis"
    }

    JUDGE_LANGUAGE_VALUE = {
        'codeforces' : {
            'C++' : '61'
        },
        'atcoder' : {
            'C++' : '4003'
        },
        'kattis' : {
            'C++' : 'C++'
        },
        'spoj' : {
            'C++' : '44'
        }
    }

    username: str
    password: str

    def current_millisecond_time(self):
        return round(time.time() * 1000)

    def __init__(self, username = "", password = ""):
        self.username = username
        self.password = password

    def get_vjudge_problem_link(self, problem_link):
        judge_name = ''
        for marker in self.JUDGE_MARKER.keys():
            if marker in problem_link:
                judge_name = self.JUDGE_MARKER[marker]
                break
        if judge_name == '':
            return None
        add = ''
        if judge_name == 'codeforces':
            lst = problem_link.split('/')
            if lst[-2] == 'problem':
                add = lst[-3] + lst[-1];
            else:
                add = lst[-2] + lst[-1]
        elif judge_name == 'atcoder' or judge_name == 'spoj' or judge_name == 'kattis':
            add = problem_link.split('/')[-1]
        if (judge_name == 'atcoder'):
            add = add.split('?')[0] # get rid of language extension
        return [judge_name, self.PROBLEM_URL + self.JUDGE_PREFIX[judge_name] + '-' + add]

    def submit_solution(self, problem_link, solution): 
        # Logging in
        
        options = Options()
        options.add_argument('--headless')
        options.add_argument('--disable-gpu')  # Last I checked this was necessary.
        driver = webdriver.Chrome(chrome_options=options)
        driver.get(self.JUDGE_URL)
        wait = WebDriverWait(driver, 10)
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/nav/div/ul/li[8]/a"))).click()
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[4]/div/div/div[2]/form/div[1]/input"))).send_keys(self.username)
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[4]/div/div/div[2]/form/div[2]/input"))).send_keys(self.password)
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[4]/div/div/div[3]/button[3]"))).click()
        judge_name, submission_url = self.get_vjudge_problem_link(problem_link)
        # Submitting Solution
        driver.get(submission_url)
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[1]/div/div[1]/div[2]/div/div[1]/div[1]/button"))).click()
        select = Select(wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[3]/div/div/div[2]/form/div/div[4]/div/select"))))
        select.select_by_value(self.JUDGE_LANGUAGE_VALUE[judge_name][solution.language])
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[3]/div/div/div[2]/form/div/div[6]/div/textarea"))).send_keys(solution.solution_code + "\n// " + str(self.current_millisecond_time()))
        wait.until(EC.element_to_be_clickable((By.XPATH, "/html/body/div[3]/div/div/div[3]/button[2]"))).click()
        start = time.time()
        while True: 
            text = wait.until(EC.visibility_of_element_located((By.XPATH, "/html/body/div[3]/div/div/div[2]/div[1]/table/tbody/tr[1]/td"))).text
            text = text.split(' ')[0]
            if text in self.GOOD_VERDICTS:
                driver.quit()
                return True
            elif text in self.BAD_VERDICTS:
                driver.quit()
                return False
            time.sleep(0.25)
            if time.time() - start>= 60:
                break
        driver.quit()
        return False

class Codeforces:
    JUDGE_NAME = "codeforces"
    JUDGE_URL = "https://codeforces.com/"
    LOGIN_URL = "https://codeforces.com/enter"
    SUBMISSION_URL = "https://codeforces.com/problemset/submit"
    RESULT_URL = "https://codeforces.com/contest/"
    LANGUAGES = {
        "C" : "43", #GNU GCC C11 5.1.0
        "java" : "36", # Java 1.8.0_241
        "cpp" : "61", # 
        "C++" : "61", # C++ 17 64 bit
        "py" : "41" #PyPy 3.6 (7.2.0)
    }

    username: str
    password: str
    logged_in: bool
    br: mechanize.Browser

    def __init__(self, username = "", password = ""):
        self.username = username
        self.password = password
        self.logged_in = False
        self.br = mechanize.Browser()

        # Browser options
        self.br.set_handle_equiv(True)
        self.br.set_handle_gzip(True)
        self.br.set_handle_redirect(True)
        self.br.set_handle_referer(True)
        self.br.set_handle_robots(False)
        self.br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time = 1)

        self.br.addheaders = [('User-agent', 'Chrome')]

    def login(self):
        # print("Trying to log into CodeForces: " + self.username)
        # The site we will navigate into, handling it's session
        self.br.open(self.LOGIN_URL)

        # Select the second (index one) form (the first form is a search query box)
        # Logging in
        self.br.select_form(nr = 1)
        self.logged_in = True
        
        self.br.form['handleOrEmail'] = self.username
        self.br.form['password'] = self.password

        res = self.br.submit()

        if res.geturl() == self.JUDGE_URL:
            # print("Logged In Successfully")
            return True
        else:
            # print("CF: Sorry, wrong username/password. Please try again.")
            self.logged_in = False
            return False

    def get_contest_number(self, problem_id):
        res = ''
        for i in range(len(problem_id)):
            if problem_id[i].isdigit():
                res += problem_id[i]
            else:
                break
        return int(res)

    def current_millisecond_time(self):
        return round(time.time() * 1000)

    def submit_solution(self, problem, solution):
        if not self.logged_in:
            self.login()
        self.br.open(self.SUBMISSION_URL)
        self.br.select_form(nr = 1)
        
        self.br.form.find_control(name = "programTypeId").value = [self.LANGUAGES[solution.language]]
        self.br.form.find_control(name = "submittedProblemCode").value = str(problem.problem_id)
        self.br.form.find_control(name = "source").value = solution.solution_code + "\n// " + str(self.current_millisecond_time())
        res = self.br.submit()
        if "https://codeforces.com/problemset/status?my=on" != str(res.geturl()):
            return ""
            
        # then we should check if the verdict has been given
        # should check repeatedly delaying 5-10 secs and stop when a verdict is given
        time.sleep(0.25)
        response = requests.get("https://codeforces.com/api/user.status?handle=" + self.username + "&from=1&count=1")
        submission_id = ""
        if response.status_code == 200:
            try:
                data = json.loads(response.content.decode('utf-8'))
            except:
                return False
            submission_id = data['result'][0]['id']
        else:   
            # print("Could't get submission id. Please try this problem again later.")
            return False

        submission_url = self.RESULT_URL + str(self.get_contest_number(problem.problem_id)) + '/submission/' + str(submission_id)

        # wait for result

        start = time.time()
        time.sleep(0.25)
        
        # print(submission_url)
        
        while True:
            if (time.time() - start >= 60):
                break
            response = requests.get("https://codeforces.com/api/user.status?handle=" + self.username + "&from=1&count=1")
            try: 
                data = json.loads(response.content.decode('utf-8'))
            except:
                time.sleep(0.5)
                continue
            
            data = data['result'][0]

            if 'verdict' not in data.keys():
                continue
            
            try:
                verdict = str(data['verdict'])
            except:
                traceback.print_exc()
                # print(data)
                return False

            if verdict == "TESTING":
                time.sleep(0.25)
            else:
                if verdict == "OK":
                    return True
                else:
                    return False
                break
                
        return False

