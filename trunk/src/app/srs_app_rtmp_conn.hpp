/*
The MIT License (MIT)

Copyright (c) 2013-2014 winlin

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef SRS_APP_RTMP_CONN_HPP
#define SRS_APP_RTMP_CONN_HPP

/*
#include <srs_app_rtmp_conn.hpp>
*/

#include <srs_core.hpp>

#include <srs_app_st.hpp>
#include <srs_app_conn.hpp>
#include <srs_app_reload.hpp>
#include <srs_protocol_stack.hpp>
#include <map>
#include <utility/shared_ptr/shared_ptr.hpp>

class SrsRtmpServer;
class SrsRequest;
class SrsResponse;
class SrsSource;
class SrsRefer;
class SrsConsumer;
class SrsMessage;
class SrsStSocket;
#ifdef SRS_AUTO_HTTP_CALLBACK    
class SrsHttpHooks;
#endif
class SrsBandwidth;
class SrsKbps;
class SrsRtmpClient;
class SrsSharedPtrMessage;
class SrsRtmpConn;
class SrsNetStream;

class SrsNetStream{
public:
	SrsNetStream(int _stream_id): stream_id(_stream_id), source(NULL), consumer(NULL), type(DEFAULT){};
	virtual ~SrsNetStream(){ source = NULL; }

	int get_stream_id() const { return stream_id;}
	void set_stream_id(int _stream_id) { stream_id = _stream_id; }
	std::string get_name() const{ return stream_name; }
	void set_name(std::string &_name) { stream_name = _name;};

	SrsSource* get_source() const { return source; }
	void set_source(SrsSource* _source){ source = _source; }

	void set_type_publisher() { type = PUBLISHER; }
	bool is_publisher() const { return type == PUBLISHER; }

	void set_type_player() { type = PLAYER;}
	bool is_player() const { return type == PLAYER; }

	srs::shared_ptr<SrsConsumer> get_consumer() const { return consumer;};
	void set_consumer(srs::shared_ptr<SrsConsumer> _consumer) { consumer = _consumer;}
private:
	enum Type {
		DEFAULT,
		PUBLISHER,
		PLAYER
	};
	int	stream_id;
	std::string stream_name;
	SrsSource* source;
	srs::shared_ptr<SrsConsumer> consumer;
	Type type;
};

/**
* the client provides the main logic control for RTMP clients.
*/
class SrsRtmpConn : public virtual SrsConnection, public virtual ISrsReloadHandler
{
private:
    SrsRequest* req;
    SrsResponse* res;
    SrsStSocket* skt;
    SrsRtmpServer* rtmp;
    SrsRefer* refer;
    SrsBandwidth* bandwidth;
    // elapse duration in ms
    // for live play duration, for instance, rtmpdump to record.
    // @see https://github.com/winlinvip/simple-rtmp-server/issues/47
    int64_t duration;
    SrsKbps* kbps;
	double  next_stream_id;
	std::map<double, SrsNetStream*> streams;
public:
    SrsRtmpConn(SrsServer* srs_server, st_netfd_t client_stfd);
    virtual ~SrsRtmpConn();
public:
    virtual void kbps_resample();
protected:
    virtual int do_cycle();
// interface ISrsReloadHandler
public:
    virtual int on_reload_vhost_removed(std::string vhost);
// interface IKbpsDelta
public:
    virtual int64_t get_send_bytes_delta();
    virtual int64_t get_recv_bytes_delta();
private:
	virtual int on_set_chunk_size(SrsMessage* );
	virtual int on_abort_message(SrsMessage* );
	virtual int on_acknowledgement(SrsMessage* );
	virtual int on_user_control_messages(SrsMessage* );
	virtual int on_window_acknowledgement_size(SrsMessage* );
	virtual int on_set_peer_bandwidth(SrsMessage* );
	virtual int on_audio_message(SrsMessage* );
	virtual int on_video_message(SrsMessage* );
	virtual int on_amf3_command_message(SrsMessage* );
	virtual int on_amf3_data_message(SrsMessage* );
	virtual int on_amf3_shared_object(SrsMessage* );
	virtual int on_amf0_command_message(SrsMessage* );
	virtual int on_amf0_data_message(SrsMessage* );
	virtual int on_amf0_shared_object(SrsMessage* );
	virtual int on_aggregate_message(SrsMessage* );
private:
	void set_netstream(SrsNetStream* stream) { streams[stream->get_stream_id()] = stream; }
	SrsNetStream* get_netstream(int stream_id) { return (streams.find(stream_id) == streams.end()) ? NULL : streams[stream_id];}
private:
    // when valid and connected to vhost/app, service the client.
    virtual int service_cycle();
    // stream(play/publish) service cycle, identify client first.
    virtual int stream_service_cycle();
	virtual int message_loop();
    virtual int check_vhost();
    virtual int playing(SrsSource* source);
    virtual int fmle_publishing(SrsSource* source);
    virtual int do_fmle_publishing(SrsSource* source);
    virtual int flash_publishing(SrsSource* source);
    virtual int do_flash_publishing(SrsSource* source);
    virtual int process_publish_message(SrsSource* source, SrsMessage* msg, bool vhost_is_edge);
    virtual int process_play_control_msg(SrsConsumer* consumer, SrsMessage* msg);
private:
    virtual int check_edge_token_traverse_auth();
    virtual int connect_server(int origin_index, st_netfd_t* pstsock);
    virtual int do_token_traverse_auth(SrsRtmpClient* client);
private:
    virtual int  http_hooks_on_connect();
    virtual void http_hooks_on_close();
    virtual int  http_hooks_on_publish();
    virtual void http_hooks_on_unpublish();
	virtual int  http_hooks_on_play();
	virtual void http_hooks_on_stop();
	virtual void http_hooks_on_error();
	virtual void http_hooks_on_call(SrsCallPacket *call);
};

#endif
/* vim: set ts=4 sts=4 sw=4 expandtab : */
