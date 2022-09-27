import econ_data
import excess_deaths
import state_demo
import google_mobility
import state_testing
import States_CDC_Hazhir_HREdits
from datetime import datetime

#need to add econ data
state_start = datetime.now()
#econ_data.main()
print(f"Econ data time: {datetime.now()-state_start}")
state_start = datetime.now()
excess_deaths.main()
print(f"Deaths data time: {datetime.now()-state_start}")
state_start = datetime.now()
state_demo.main()
print(f"Demo data time: {datetime.now()-state_start}")
print("WARNING: Fetching google mobility data takes a while (5 minutes), it's not frozen")
state_start = datetime.now()
google_mobility.main(update_data=True)
print(f"Mobi data time: {datetime.now()-state_start}")
state_start = datetime.now()
state_testing.main()
print(f"Test data time: {datetime.now()-state_start}")
state_start = datetime.now()
States_CDC_Hazhir_HREdits.main(update_data=True)
print(f"Rest data time: {datetime.now()-state_start}")