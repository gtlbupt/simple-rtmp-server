
C ==> S
Handshake C0 + C1
Handshake S0 + S1 + S2
Handshake C2

Client => Server
connect("live")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: 
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	"connect"		: command_name {String}
	1				: transaction_id {Number}
	{				: CommandObject		 {Object}
	"app": "live",
	"type" "nonprivate",
	"flashVer": "FMLE/3.0 (compatible: lavf55.33.100)",
	"tcUrl": "rtmp://cp01-wise-2011q4ecom05.cp01.baidu.com:8935/live"
	"swfUrl": "rtmp://cp01-wise-2011q4ecom05.cp01.baidu.com:8935/live"
	}

Server => Client
Window Acknowledgement Size
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 2
	Timestamp		: 0
	Body Size		: 4
	Type ID			: Window Acknowledgement Size (0x05)
	Stream ID		: 0
RTMP-Body:
	Window Acknowledgement Size: 2.5*1000*1000 int32_t big-endian

Server => Client
Set Peer Bandwidth 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 2
	Timestamp		: 0
	Body Size		: 5
	Type ID			: Set Peer Bandwidth(0x06)
	Stream ID		: 0
RTMP-Body:
	Window Acknowledgement Size: 2.5*1000*1000 int32_t big-endian
	limit type		:		0x02		int8_t 


Server => Client
_result("NetConnection.Connect.Success")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name {striing}: "_result"
	transaction_id {Number}: 1
	CommandObject  {Object}: { "fmsVer": "FMS/3,5,3,888", "capabilities" : 127, "mode": 1 },
	CommandObject  {Object}: { "level": "status", "code" : "NetConnection.Connect.Success", "objectEncoding": 0, "description": "connection succeeded"},

Server => Client
onBWDone
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name  {striing}: "onBWDone"
	transaction_id {Number}: 0
	CommandObject    {Null}: null


Client => Server
releaseStream("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	TimestampDelta	: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "releaseStream",
	transaction_id {Number}: 2
	CommandObject  {Null}  : Null
	CommandObject  {String}: "immt" 

Client => Server
FCPublish("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "FCPublish",
	transaction_id {Number}: 3
	CommandObject  {Null}  : Null
	CommandObject  {String}: "immt" 

Client => Server
createStream()
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "createStream",
	transaction_id {Number}: 4
	CommandObject  {Null}  : Null

Client => Server
_checkbw()
RTMP-Header:
	Format			: 1
	Chunk Stream ID	: 3
	Timestamp		: 0
	TimestampDelta	: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "_checkbw",
	transaction_id {Number}: 5
	CommandObject  {Null}  : Null


Server => Client
_result() => releaseStream
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name {striing}: "_result"
	transaction_id {Number}: 2
	CommandObject  {Null}: Null
	CommandObject  {Undefined}: Undefined

Server => Client
Set Chunk Size
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 2
	Timestamp		: 0
	Body Size		: 4
	Type ID			: Set Chunk Size(0x01)
	Stream ID		: 0
RTMP-Body:
	Set Chunk Size: 6000 int32_t big-endian

Server => Client
_result() => FCPublish 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name {striing}: "_result"
	transaction_id {Number}: 3
	CommandObject  {Null}: Null
	CommandObject  {Undefined}: Undefined

Server => Client
_result() => createStream 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name {striing}: "_result"
	transaction_id {Number}: 4
	CommandObject  {Null}: Null
	CommandObject  {Number}: 1


Client => Server 
Set Chunk Size
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 2
	Timestamp		: 0
	Body Size		: 4
	Type ID			: Set Chunk Size(0x01)
	Stream ID		: 0
RTMP-Body:
	Set Chunk Size: 6000 int32_t big-endian

Client => Server
publish("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name   {String}: "publish",
	transaction_id {Number}: 0
	CommandObject  {Null}  : Null
	CommandObject  {String}: "immt" 
	CommandObject  {String}: "live" 

Server => Client
onFCPublish() 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onFCPublish"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"code": "NetStream.Publish.Start",
		"description": "Started publishing stream."		
	}

Server => Client
onStatus("NetStream.Publish.Start") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"level": "status",
		"code": "NetStream.Publish.Start",
		"description": "Started publishing stream.",
		"clientId" : "ASAICiss"
	}


Client => Server

RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: 
	Type ID			: AMF0 Data (0x12)
	Stream ID		: 1
RTMP-Body:
	command_name {String}: "@setDataFrame",
	command_name {String}: "onMetaData",
	CommandObject {ECMAarray}: 
	[ 17 item
	"duration": 0,
	"width": 640,
	"height": 352,
	"videodatarate" : 385,
	"framerate"		: 25,
	"videocodecid"	: 7,
	"audiocdatarate": 63,
	"audiosamplerate": 44100,
	"audiosamplesize": 16,
	"stereo"		 : true
	"audiocodecid"	 : 10,
	"audiodelay"	 : '0',
	"canSeekToEnd"	 : 'true',
	"lasttimestamp"  : "1730"
	"metadatacreator": "PFree FLV Lib",
	"encoder"		: "lavf55.33.100",
	"filesize"		: 0,
	]

Client => Server
Video
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: ?
	Type ID			: Video Data(0x09)
	Stream ID		: 1
RTMP-Body:
	payload

Client => Server
Audio
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: ?
	Type ID			: Audio Data(0x08)
	Stream ID		: 1
RTMP-Body:
	payload


/****************** stop publish ********************/
Client => Server
FCUnpublish("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	TimestampDelta	: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "FCUnpublish",
	transaction_id {Number}: 5
	CommandObject  {Null}  : Null
	CommandObject  {String}: "immt" 

Client => Server
closeStream("immt")
RTMP-Header:
	Format			: 1
	Chunk Stream ID	: 4
	Timestamp		: 0
	TimestampDelta	: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "closeStream",
	transaction_id {Number}: 0
	CommandObject  {Null}  : Null

Client => Server
deleteStream("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	TimestampDelta	: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "deleteStream",
	transaction_id {Number}: 0
	CommandObject  {Null}  : Null
	CommandObject  {Number}: 1

Server => Client
onFCUnpublish() 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onFCUnpublish"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"code": "NetStream.Unpublish.Success",
		"description": "Stop publishing stream."		
	}

Server => Client
_result() => FCUnpublish
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onFCUnpublish"
	transaction_id {Number}: 5
	CommandObject  {Null}: Null
	CommandObject  {Undefined}: Undefined

Server => Client
onStatus("NetStream.Unpublish.Success") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"level": "status",
		"code": "NetStream.Unpublish.Success",
		"description": "Stop publishing stream.",
		"clientid":	"ASAICiss"
	}
/***************** Flash Publish ******************/

Client => Server
createStream()
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "createStream",
	transaction_id {Number}: 2
	CommandObject  {Null}  : Null

Server => Client
_result() => createStream 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name {striing}: "_result"
	transaction_id {Number}: 4
	CommandObject  {Null}: Null
	CommandObject  {Number}: 1

Client => Server
publish("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 8
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name   {String}: "publish",
	transaction_id {Number}: 0
	CommandObject  {Null}  : Null
	CommandObject  {String}: "immt" 
	CommandObject  {String}: "live" 
client => server 
@setDataFrame
RTMP-Header:
	Format			: 1
	Chunk Stream ID	: 8
	Timestamp		: 0
	Body Size		: 
	Type ID			: AMF0 Data (0x12)
RTMP-Body:
	command_name {String}: "@setDataFrame",
	command_name {String}: "onMetaData",
	CommandObject {ECMAarray}: 
	[ 17 item
	"duration": 0,
	"width": 640,
	"height": 352,
	"videodatarate" : 385,
	"framerate"		: 25,
	"videocodecid"	: 7,
	"audiocdatarate": 63,
	"audiosamplerate": 44100,
	"audiosamplesize": 16,
	"stereo"		 : true
	"audiocodecid"	 : 10,
	"audiodelay"	 : '0',
	"canSeekToEnd"	 : 'true',
	"lasttimestamp"  : "1730"
	"metadatacreator": "PFree FLV Lib",
	"encoder"		: "lavf55.33.100",
	"filesize"		: 0,
	]

Server => Client
StreamBegin
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 2
	Timestamp		: 0
	Body Size		: ?
	Type ID			: UserControlMessage(0x04)
	Stream ID		: 0
RTMP-Body:
	Event Type:		0x00, int16_t big-endian
	Event Data:		0x01, int32_t big-endian

Server => Client
onStatus("NetStream.Publish.Start") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"level": "status",
		"code": "NetStream.Publish.Start",
		"description": "Started publishing stream.",
		"clientId" : "ASAICiss"
	}

Client => Server
deleteStream("immt")
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 3
	Timestamp		: 0
	TimestampDelta	: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 0
RTMP-Body:
	command_name   {String}: "deleteStream",
	transaction_id {Number}: 0
	CommandObject  {Null}  : Null
	CommandObject  {Number}: 1

/***************** Flash play stream *************/
client => server
play("livestream") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 8
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "play"
	transaction_id {Number}: 4
	CommandObject  {Null}: Null
	CommandObject  {striing}: "livestream"
	CommandObject  {Number}: -2

client => server
play("livestream") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 8
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "play"
	transaction_id {Number}: 4
	CommandObject  {Null}: Null
	CommandObject  {striing}: "livestream"
	CommandObject  {Number}: -2

Server => Client
Set Chunk Size

Server => Client
StreamBegin
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 2
	Timestamp		: 0
	Body Size		: ?
	Type ID			: UserControlMessage(0x04)
	Stream ID		: 0
RTMP-Body:
	Event Type:		0x00, int16_t big-endian
	Event Data:		0x01, int32_t big-endian

Server => Client
onStatus("NetStream.Play.Reset") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"level": "status",
		"code": "NetStream.Play.Reset",
		"description": "Playing and Resetting stream. publishing stream.",
		"clientId" : "ASAICiss"
	}

Server => Client
onStatus("NetStream.Play.Start") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		"level": "status",
		"code": "NetStream.Play.Start",
		"description": "Playing and Resetting stream. publishing stream.",
		"clientId" : "ASAICiss"
	}

Server => Client
|RtmpSampleAccess()
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x14)
	Stream ID		: 1
RTMP-Body:
	command_name   {striing}: "|RtmpSampleAccess"
	CommandObject  {Boolean}: false 
	CommandObject  {Boolean}: false 

Server => Client
onStatus("NetStream.Data.Start") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 5
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x12)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		// "level": "status",
		"code": "NetStream.Play.Start",
	}

Server => Client
onStatus("NetStream.Data.Start") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x12)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onStatus"
	transaction_id {Number}: 0
	CommandObject  {Null}: Null
	CommandObject  {object}: {
		// "level": "status",
		"code": "NetStream.Play.Start",
	}

Server => Client
onStatus("NetStream.Data.Start") 
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: ?
	Type ID			: AMF0 Command (0x12)
	Stream ID		: 1
RTMP-Body:
	command_name {striing}: "onMetaData"
	CommandObject  {object}: {
		"duration": 0,
		"width"	  : 640,
		"heigth"  : 400,
		"videodatarate" : 444.1171875,
		"framerate"		: 1000,
		"videocodecid"	: 7,
		"audiodatarate"	: 125,
		"audiosamplerate": 44100,
		"stero"			: true,
		"audiocodecid"	: 10,
		"major_brand"	: "isom",
		"minor_version"	: "1",
		"compatible_brands"	: "isomavc1",
		"encoder"		: "Lavf54.63.104",
		"filesize"		: 0,

		"code": "NetStream.Play.Start",
	}

Server => Client:
Video
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 6
	Timestamp		: 0
	Body Size		: ?
	Type ID			: Video Data(0x09)
	Stream ID		: 1
RTMP-Body:
	payload

Server => Client:
Audio
RTMP-Header:
	Format			: 0
	Chunk Stream ID	: 4
	Timestamp		: 0
	Body Size		: ?
	Type ID			: Audio Data(0x08)
	Stream ID		: 1
RTMP-Body:
	payload

