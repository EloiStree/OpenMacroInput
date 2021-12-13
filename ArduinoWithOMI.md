To make it short, you can write all the input of your Arduino project as such #01010|136464.  
#digital from 0-1|analogvaluefrom 0-9  

And the following file in the OMI program with translate them to boolean named usable to trigger actions.

Example
```#1100|3```
- D0 : Foot left at down is pressed
- D1 : Foot right at down is pressed
- D2 : Foot left at top is release
- D3 : Foot right at top is release
- A1 : Light of the room is almost dark


Meaning that now you can made condition like this:
FootLD + FootRD then do something.
!FootLD + !FootRD +!FootLT + !FootRT then pause the game.


Example:
```
<?xml version="1.0" encoding="utf-8"?>

<AnalogDigitalCompressConfig>

  <PortConnections>
    <PortConnection portId="20" patternName="Foot with four buttons and light" />
  </PortConnections>
  <AnalogDigitalCompressPatterns>
      <AnalogDigitalCompressPattern name="Foot with four buttons and light" docUrl="">
        <digit index="0" label="FootLD" />
        <digit index="1" label="FootRD" />
        <digit index="2" label="FootLT" />
        <digit index="3" label="FootRT" />
        <analog index="0" label="LightOfRoom" from="5" to="9"/>
      </AnalogDigitalCompressPattern>
   </AnalogDigitalCompressPatterns>
</AnalogDigitalCompressConfig>
```


File structure use to rename the input to boolean
```
<?xml version="1.0" encoding="utf-8"?>
<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" xmlns:xs="http://www.w3.org/2001/XMLSchema">
  <xs:element name="AnalogDigitalCompressConfig">
    <xs:complexType>
      <xs:sequence>
        <xs:element name="PortConnections">
          <xs:complexType>
            <xs:sequence>
              <xs:element maxOccurs="unbounded" name="PortConnection">
                <xs:complexType>
                  <xs:attribute name="portId" type="xs:unsignedInt" use="required" />
                  <xs:attribute name="patternName" type="xs:string" use="required" />
                </xs:complexType>
              </xs:element>
            </xs:sequence>
          </xs:complexType>
        </xs:element>
        <xs:element name="AnalogDigitalCompressPatterns">
          <xs:complexType>
            <xs:sequence>
              <xs:element maxOccurs="unbounded" name="AnalogDigitalCompressPattern">
                <xs:complexType>
                  <xs:sequence>
                    <xs:element name="digital">
                      <xs:complexType>
                        <xs:attribute name="index" type="xs:unsignedInt" use="required" />
                        <xs:attribute name="label" type="xs:string" use="required" />
                        <xs:attribute name="inverse" type="xs:boolean" use="optional" />
                      </xs:complexType>
                    </xs:element>
                    <xs:element name="analog">
                      <xs:complexType>
                        <xs:attribute name="index" type="xs:unsignedInt" use="required" />
                        <xs:attribute name="label" type="xs:string" use="required" />
                        <xs:attribute name="from" type="xs:short" use="required" />
                        <xs:attribute name="to" type="xs:short" use="required" />
                        <xs:attribute name="inverse" type="xs:boolean" use="optional" />
                      </xs:complexType>
                    </xs:element>
                  </xs:sequence>
                  <xs:attribute name="name" type="xs:string" use="required" />
                  <xs:attribute name="docUrl" type="xs:string" use="required" />
                </xs:complexType>
              </xs:element>
            </xs:sequence>
          </xs:complexType>
        </xs:element>
      </xs:sequence>
    </xs:complexType>
  </xs:element>
</xs:schema>
```

## Arduino example of code
###  Simple Button
"Do to later ping me if your need this code"

###  Light Sensor
"Do to later ping me if your need this code"

###  Magnet
"Do to later ping me if your need this code"

###  Paint / Capacitive sensor
"Do to later ping me if your need this code"


