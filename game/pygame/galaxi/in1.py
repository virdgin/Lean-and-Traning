import pygame


class Inop1(pygame.sprite.Sprite):
    """пришелец"""

    def __init__(self, screen):
        # подтягивает класс от которого наследуется
        super(Inop1, self).__init__()
        self.screen = screen
        self.image = pygame.image.load('galaxi\images\in1.png')
        self.rect = self.image.get_rect()  # преобразовали изображение
        self.rect.x = self.rect.width  # отслеживание движения по ширине
        self.rect.y = self.rect.height  # отслеживание движения по высоте
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

    def draw(self):
        '''вывод пришельца на экран'''
        self.screen.blit(self.image, self.rect)

    def update(self):
        '''движение пришельцев'''
        
        self.y += 0.1
        self.rect.y = self.y
