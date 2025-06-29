| title | Author | description | createed_at
| NormalPad | Nathan Tsai | A 75% Keyboard w/82 Silent tactile switches | 2024-12-26|

Time spent: ~30-40 hours total
*Note: Although I started this project for Hackpad v2, I never got around to finishing it until recently. At this point, I had finished the main CAD, a relatively finished BOM and main PCB, which probably took around 20-30 hours of time - I redid the CAD case 2-3 times, as I didn't like the design structure and it didn't fit the pcb, and the PCB layout took a while since I rewired the copper multiple times. 
*Another note: I didn't keep good track of my time while creating my project, so it might be very inaccurate.

## June 24th: Checking PCB
Since I had finished my PCB, I thought about checking the PCB to make sure each part fit. I checked the BOM, and realized that although the Kailh hot swap keys and stabilizers seemed to fit, the diodes were the wrong size. Apperantly I had used D-35 7.62mm resister footprint but I wanted to buy D-41 10.16mm as they came in for a relatively good price($5 for 100pc at Amazon). Thus I found the right footprint after spending a lot of time trying to match the 7.62mm diode, and exploring SMD options to assemble at JLCPCB instead of soldering it myself. Eventually I realized that this was a waste of time, as I could have taken a different footprint - the D-41 10.16mm one, which I found after searching the Kicad library multiple times. 
Time: ~2 Hours
<b>One switch but this process with 82 keys instead of one as pictured here</b>
![one switch](./src/one_switch.png)

## June 25th: Checking validation between whole project
Since I had finished my project, I wanted to make sure that the whole project was going to be ok. First, I checked the CAD design. I realized that there weren't any supports, so i added a 0.4mm unstable support for the bottoms of the cad case that hopefully doesn't fall apart during printing for the case - fingers crossed! Then I checked the BOM for anything that seemed off. There didn't seem to be anything off, but I was really confused about how the shipping worked. Time to take a break!

Time: ~2-3 Hours

<b>the supports</b> Basically I split the bottom keyboard in half to make it easier to find people who could print the full size keyboard
![bottom_left](./src/support.png)

## June 26th: Frantically checking shipping prices
I had forgot about CAD shipping until yesterday. I haven't used USPS before, but I checked their website to see how much shipping would cost. It took a while to find their Priority Mail page where I found it would cost around $10.75 for shipping. I'm still hesitant on that number, though, as the package could be bigger than expected or the mail people might upcharge. Otherwise, it should be fine. The most annoying part, though, was trying to convert the keyboard dimensions from mm to inches, where I used a number converter. I kept forgetting the numbers as there were too many and I guessed some of them(4 - length, width, height, and weight)

Time ~1-2 hours

## June 27th: Finishing up project
I realized that my split bottom was more of a hassle than an asset, so I spent some time finishing it. I also finished the README, taking a lot of pictures, which was kind of annoying.

Time: ~1-2 hours

The amount of pictures I added to the README(excluding ~5 pictures)
![list](./src/list.png)

*Sidenote: My computer insisted upon deleting random files, and Onedrive complained that I should upload my precious files into its tiny 5 GB cloud storage. I clicked ok, and now my files are messed up :(

## June 28th: Billing issues
Originally, I had planned to get a lot of sources from Amazon as the prices were actually and looked more reliable than Aliexpress. However, I had seen that they had charged me $20 in unknown price fees, shipping not included. I took a while trying to source parts from different sources than Amazon, which actually was annoying as I wanted to lower the price but keep the quality of my products. Sadly, I took out my durock silent t1 shrimps key switch from the BOM to lower the overall cost

Time: 3-5 hours