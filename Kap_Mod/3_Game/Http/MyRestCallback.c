// Script File
class ResponseFromBack
{
    array<string> items;
	string id;
};
class ResponseCoords
{
	string netId;
    array<string> coord;
};

class MyRestCallback: RestCallback {
    override void OnSuccess( string data, int dataSize )
    {
        // override this with your implementation
        Print(" !!! OnSuccess() size=" + dataSize );
		Print("Success: " + GetGame().IsServer());
        if( dataSize > 0 ){
            //Print(data); // !!! NOTE: Print() will not output string longer than 1024b, check your dataSize !!!
            ResponseCoords resp = new ResponseCoords();
            string error;
            JsonSerializer js = new JsonSerializer();
            bool ok = js.ReadFromString(resp, data, error);
			//PlayerBase player;
			Print(resp.netId);
			Print(resp.coord[0]);
			Print(resp.coord[1]);
			Print("CNT: " + resp.coord.Count());
			string playerId = resp.netId;
			string posX;
			string posZ;
			if(resp.coord.Count() > 0){
				posX = resp.coord[0];
				posZ = resp.coord[1];
				Param param = new Param2<string, string>(posX + "," + posZ,playerId);
				GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_TELEPORT, param, true, GetGame().GetPlayer().GetIdentity());
			}else{
				error = "Coords empty";
			};
            Print("ERR: " + error);
    };
	};
	override void OnFileCreated( string fileName, int dataSize )
	{
		Print(" !!! OnFileCreated() file=" + fileName + " size=" + dataSize );
	};
};
