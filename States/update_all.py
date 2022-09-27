import econ_data
import excess_deaths
import state_demo
import google_mobility
import state_testing
import States_CDC_Hazhir_HREdits
from datetime import datetime
import threading
def do_econ():
    state_start = datetime.now()
    econ_data.main()
    print(f"Econ data time: {datetime.now()-state_start}")
def do_excess_deaths():
    state_start = datetime.now()
    excess_deaths.main()
    print(f"Deaths data time: {datetime.now()-state_start}")
def do_state_demo():
    state_start = datetime.now()
    state_demo.main()
    print(f"Demo data time: {datetime.now()-state_start}")
def do_mobi():
    print("WARNING: Fetching google mobility data takes a while (5 minutes), it's not frozen")
    state_start = datetime.now()
    google_mobility.main(update_data=True)
    print(f"Mobi data time: {datetime.now()-state_start}")
def do_testing():
    state_start = datetime.now()
    state_testing.main()
    print(f"Test data time: {datetime.now()-state_start}")
def do_rest():
    state_start = datetime.now()
    States_CDC_Hazhir_HREdits.main(update_data=True)
    print(f"Rest data time: {datetime.now()-state_start}")

def main():
    econ_thread=threading.Thread(target=do_econ)
    excess_deaths_thread=threading.Thread(target=do_excess_deaths)
    state_demo_thread=threading.Thread(target=do_state_demo)
    mobi_thread=threading.Thread(target=do_mobi)
    testing_thread=threading.Thread(target=do_testing)
    rest_thread=threading.Thread(target=do_rest)
    threads = [
        econ_thread,
        excess_deaths_thread,
        state_demo_thread,
        mobi_thread,
        testing_thread,
        rest_thread
    ]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()

if __name__ == "__main__":
    main()