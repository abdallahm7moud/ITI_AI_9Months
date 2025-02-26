import requests

class WeatherAPIClient:
    BASE_URL = "http://api.weatherapi.com/v1"

    def __init__(self, api_key):
        self.api_key = api_key

    def get_current_temperature(self, city):
        endpoint = f"{self.BASE_URL}/current.json"
        params = {"key": self.api_key, "q": city}
        response = requests.get(endpoint, params=params)
        response.raise_for_status()
        data = response.json()
        return data['current']['temp_c']


    def get_lat_and_long(self, city):
        endpoint = f"{self.BASE_URL}/current.json"
        params = {"key": self.api_key, "q": city}
        response = requests.get(endpoint, params=params)
        response.raise_for_status()
        data = response.json()
        location = data['location']
        return location['lat'], location['lon']
    

client = WeatherAPIClient("8b89926f794043b08d4140031242611")
print("current temperature: ",client.get_current_temperature("New York"))
print("lat and long",client.get_lat_and_long("New York"))

