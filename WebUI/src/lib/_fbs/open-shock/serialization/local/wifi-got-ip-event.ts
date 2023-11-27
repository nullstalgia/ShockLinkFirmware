// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

export class WifiGotIpEvent {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):WifiGotIpEvent {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsWifiGotIpEvent(bb:flatbuffers.ByteBuffer, obj?:WifiGotIpEvent):WifiGotIpEvent {
  return (obj || new WifiGotIpEvent()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsWifiGotIpEvent(bb:flatbuffers.ByteBuffer, obj?:WifiGotIpEvent):WifiGotIpEvent {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new WifiGotIpEvent()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

ip():string|null
ip(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
ip(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

static startWifiGotIpEvent(builder:flatbuffers.Builder) {
  builder.startObject(1);
}

static addIp(builder:flatbuffers.Builder, ipOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, ipOffset, 0);
}

static endWifiGotIpEvent(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createWifiGotIpEvent(builder:flatbuffers.Builder, ipOffset:flatbuffers.Offset):flatbuffers.Offset {
  WifiGotIpEvent.startWifiGotIpEvent(builder);
  WifiGotIpEvent.addIp(builder, ipOffset);
  return WifiGotIpEvent.endWifiGotIpEvent(builder);
}
}
