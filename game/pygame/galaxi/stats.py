class Stats():
    '''отслеживание статистики'''
    
    def __init__(self):
        """инициализация статистики"""
        self.reset_stats()
    
    def reset_stats(self):
        """изменение статистики """
        self.guns_left= 2