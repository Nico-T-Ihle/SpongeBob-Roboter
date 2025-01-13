import time

# Pin-Nummern definieren
IN1 = 18
IN2 = 22
ENA = 25
IN3 = 27
IN4 = 5
ENB = 6

# GPIO-Modus setzen
GPIO.setmode(GPIO.BCM)
GPIO.setup(IN1, GPIO.OUT)
GPIO.setup(IN2, GPIO.OUT)
GPIO.setup(ENA, GPIO.OUT)
GPIO.setup(IN3, GPIO.OUT)
GPIO.setup(IN4, GPIO.OUT)
GPIO.setup(ENB, GPIO.OUT)

# PWM initialisieren
pwm_a = GPIO.PWM(ENA, 1000)
pwm_b = GPIO.PWM(ENB, 1000)
pwm_a.start(0)
pwm_b.start(0)

def motor_forward():
    GPIO.output(IN1, GPIO.HIGH)
    GPIO.output(IN2, GPIO.LOW)
    pwm_a.ChangeDutyCycle(100)
    GPIO.output(IN3, GPIO.HIGH)
    GPIO.output(IN4, GPIO.LOW)
    pwm_b.ChangeDutyCycle(100)

def motor_stop():
    GPIO.output(IN1, GPIO.LOW)
    GPIO.output(IN2, GPIO.LOW)
    pwm_a.ChangeDutyCycle(0)
    GPIO.output(IN3, GPIO.LOW)
    GPIO.output(IN4, GPIO.LOW)
    pwm_b.ChangeDutyCycle(0)

try:
    while True:
        motor_forward()
        time.sleep(5)  # Motor läuft 5 Sekunden vorwärts
        motor_stop()
        time.sleep(5)  # Motor stoppt 5 Sekunden

except KeyboardInterrupt:
    GPIO.cleanup()  # Reinigung der GPIO-Pins